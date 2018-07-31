// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "XMPPType.h"

#include "MucChat.generated.h"

/**
 * 
 */


UCLASS()
class OPENFIRECHAT_API UMucChat : public UObject
{
	GENERATED_BODY()
	
public:
	UMucChat(const FObjectInitializer &ObjectInitializer);
	void GetXmppChatPtr(const IXmppChatPtr& xmppChatPtr);
	void MucSendMessage(const FString& FromUser, const FString& Message,const FString &Type);
	void RepquestCompelete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);
	
private:
	TWeakObjectPtr<class UOpenFireChatAPI> OpenFireIntance = nullptr;
	IXmppChatPtr ChatPtr;
	FString FUser;
	FString Msg;
	FString MsgType;
	
};
