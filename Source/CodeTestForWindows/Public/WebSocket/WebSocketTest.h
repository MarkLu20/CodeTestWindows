// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WebSocketTest.generated.h"

/**
 * 
 */
class IWebSocket;
class IWebSocketsManager;
DECLARE_DELEGATE_OneParam(FMyIntDelegate, int32)
UCLASS()
class CODETESTFORWINDOWS_API UWebSocketTest : public UObject
{
	GENERATED_BODY()


public:
		UWebSocketTest(const FObjectInitializer &ObjectInitializer);

		TSharedRef<IWebSocket> CreateWebScoket(const FString& Url, const TArray<FString>& Protocols, const TMap<FString, FString>& UpgradeHeaders = TMap<FString, FString>());
		void Closeoncet();
private:
	//TSharedRef<IWebSocket> WebSocketIntance;
	
	FMyIntDelegate test;
	UFUNCTION()
	void OnConnectionError(const FString &ErrrorInfo);
	UFUNCTION()
	void OnConnected(const FString & Info);
	UFUNCTION()
	void OnClosed(int32 StatusCode,const FString &Reason,bool bWasClean);
	UFUNCTION()
	void OnMessage(const FString &MessageStr);
	
};
