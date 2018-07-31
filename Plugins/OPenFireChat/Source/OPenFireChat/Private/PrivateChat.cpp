// Fill out your copyright notice in the Description page of Project Settings.

#include "PrivateChat.h"
#include "OpenFireChatAPI.h"
#include "Runtime/Online/XMPP/Public/XmppChat.h"
#include "Engine.h"




UPrivateChat::UPrivateChat(const FObjectInitializer &ObjetInitializer):UObject(ObjetInitializer)
{
	OpenFireAPIInstance = GetDefault<UOpenFireChatAPI>();
	OpenFireAPIInstance->GetXmpptr.AddUObject(this,&UPrivateChat::GetXmppChatPtr);

}

UPrivateChat::~UPrivateChat()
{

}



void UPrivateChat::SendPrivateChatMessage(const FString& FromUser, const FString& ToUser, const FString& Message)
{   
	FXmppChatMessage ChatMessage;
	ChatMessage.FromJid.Id = FromUser;
	ChatMessage.ToJid.Id = ToUser;
	ChatMessage.Body = Message;
	FDateTime DTime = FDateTime::Now();
	DTime -= (FTimespan(8, 0, 0));
	ChatMessage.Timestamp = DTime;
	XmppChatPtr->SendChat(ToUser, ChatMessage);

}

void UPrivateChat::GetXmppChatPtr(const IXmppChatPtr& xmppChatPtr)
{
	XmppChatPtr = xmppChatPtr;
	XmppChatPtr->OnReceiveChat().AddUObject(this,&UPrivateChat::OnReceiveChat);
}

void UPrivateChat::OnReceiveChat(const TSharedRef<IXmppConnection>& Connection, const FXmppUserJid& FromJid, const TSharedRef<FXmppChatMessage>& ChatMsg)
{
	FString Time;
	
	Time = ChatMsg->Timestamp.ToString(TEXT("%Y年%m月%d日 %H:%M:%S"));
	OpenFireAPIInstance->ReceiveChatMsg.Broadcast(ChatMsg->FromJid.Id, ChatMsg->ToJid.Id, ChatMsg->Body,Time);
	GEngine->AddOnScreenDebugMessage(-1,3.0f,FColor::Purple,FString(ChatMsg->FromJid.Id+"/"+ ChatMsg->ToJid.Id+"/"+ ChatMsg->Body+"/"+ Time));
}
