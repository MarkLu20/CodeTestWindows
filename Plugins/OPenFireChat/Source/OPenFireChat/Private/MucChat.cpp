// Fill out your copyright notice in the Description page of Project Settings.

#include "MucChat.h"
#include "OPenFireChatAPI.h"
#include "Runtime/Online/XMPP/Public/Xmpp.h"
#include "Http.h"
#include "Json.h"
#include "HttpManager.h"



UMucChat::UMucChat(const FObjectInitializer &ObjectInitializer):UObject(ObjectInitializer)
{
	OpenFireIntance = GetDefault<UOpenFireChatAPI>();
	OpenFireIntance->GetXmpptr.AddUObject(this,&UMucChat::GetXmppChatPtr);
}

void UMucChat::GetXmppChatPtr(const IXmppChatPtr& xmppChatPtr)
{
	ChatPtr = xmppChatPtr;
}

void UMucChat::MucSendMessage(const FString& FromUser, const FString& Message, const FString &Type)
{
	FUser = FromUser;
	Msg = Message;
	MsgType = Type;
	
	
	
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetURL("http://192.168.2.12:8083/api/getAllUserName");
	HttpRequest->SetVerb(TEXT("GET"));
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json;charset=utf-8"));
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &UMucChat::RepquestCompelete);
	HttpRequest->ProcessRequest();
}

void UMucChat::RepquestCompelete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
{    

	FXmppChatMessage ChatMessage;
	ChatMessage.FromJid.Id = FUser;
	FString Symo = FString(L" ");
	FString Messge = Msg + Symo + MsgType;
	ChatMessage.Body = Messge;
	ChatMessage.Timestamp = FDateTime::Now();
	if (HttpResponse->GetResponseCode() == 200)
	{
		FString Content = HttpResponse->GetContentAsString();
		TArray<TSharedPtr<FJsonValue>> JsonParsed;
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(HttpResponse->GetContentAsString());
		if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
		{
			for (int32 i = 0; i < JsonParsed.Num(); i++)
			{
				FString TUser;
				
				JsonParsed[i]->TryGetString(TUser);
				ChatMessage.ToJid.Id = TUser;
				ChatPtr->SendChat(FUser,ChatMessage);
			}

		}

	}
}


