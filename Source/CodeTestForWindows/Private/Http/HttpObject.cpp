// Fill out your copyright notice in the Description page of Project Settings.

#include "HttpObject.h"
#include "Json.h"
#define LOCTEXT_NAMESPACE "UHTTPOBJECT" 
UHttpObject* UHttpObject::httpObject = nullptr;
void UHttpObject::SetUrl(FString ServerAddr)
{
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetURL(ServerAddr);
	HttpRequest->SetVerb(TEXT("GET"));
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json;charset=utf-8"));
	HttpRequest->OnProcessRequestComplete().BindUObject(this,&UHttpObject::RepquestCompelete);
	HttpRequest->ProcessRequest();
}

void UHttpObject::RepquestCompelete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
{ 
	FText SS = LOCTEXT("中俄无奈", "中文");
	if (bSucceeded)
	{
		 int32 code=HttpResponse->GetResponseCode();
		TArray<FJsonList> jsonList;
		FJsonList jsondata;
		TArray<TSharedPtr<FJsonValue>> JsonParsed;
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(HttpResponse->GetContentAsString());
		if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
		{
			for (size_t i = 0; i < JsonParsed.Num(); i++)
			{
				jsondata.Uid = FString::FromInt(JsonParsed[i]->AsObject()->GetIntegerField("uid"));
				jsondata.Userid = JsonParsed[i]->AsObject()->GetStringField("userid");
				jsondata.UserName = JsonParsed[i]->AsObject()->GetStringField("username");
				jsondata.UserPWD = JsonParsed[i]->AsObject()->GetStringField("userpwd");
				jsondata.ZoneMark = JsonParsed[i]->AsObject()->GetStringField("zonemark");
				jsonList.Add(jsondata);
				
			}
			PassJsonData.Broadcast(jsonList);
			//test.Broadcast(FString(TEXT("sadfasdfasdfasdfasdf")));
			GetURLData(jsonList);
			
		}
		
		
		//SS = TCHAR_TO_UTF8(*SS);
		//FText aa= FText::FromString(SS);
		UE_LOG(LogTemp, Error, TEXT("******************"));
	}
}

void UHttpObject::PostRepquestCompelete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
{
}

UHttpObject * UHttpObject::GetHttpObject()
{
	if (httpObject == nullptr)
	{
		httpObject = NewObject<UHttpObject>();
		httpObject->AddToRoot();
	}
	return httpObject;
}
#undef LOCTEXT_NAMESPACE 
