// Fill out your copyright notice in the Description page of Project Settings.

#include "WebSocketTest.h"
#include "Runtime/Online/WebSockets/Public/WebSocketsModule.h"
#include "Runtime/Online/WebSockets/Public/IWebSocket.h"



 UWebSocketTest::UWebSocketTest(const FObjectInitializer &ObjectInitializer)
{

}

 TSharedRef<IWebSocket> UWebSocketTest::CreateWebScoket(const FString& Url, const TArray<FString>& Protocols, const TMap<FString, FString>& UpgradeHeaders /*= TMap<FString, FString>()*/)
 {
	 TSharedRef<IWebSocket> WebSocket = FWebSocketsModule::Get().CreateWebSocket(Url, Protocols);
	// WebSocketIntance = WebSocket
	 WebSocket->OnConnected().AddUFunction(this, FName("OnConnected"));
	 WebSocket->OnConnectionError().AddUFunction(this, FName("OnConnectionError"));
	 WebSocket->OnClosed().AddUFunction(this, FName("OnClosed"));
	 WebSocket->OnMessage().AddUFunction(this, FName("OnMessage"));
	 WebSocket->Connect();
	 WebSocket->Send("TestWebSocket");
	 WebSocket->Close();
	 return  WebSocket;
 }

 void UWebSocketTest::Closeoncet()
 {

 }

 void UWebSocketTest::OnConnectionError(const FString &ErrrorInfo)
 {
	 UE_LOG(LogTemp, Error, TEXT("OnConnectionError %s"), *ErrrorInfo);
 }

 void UWebSocketTest::OnConnected(const FString & Info)
 {
	 UE_LOG(LogTemp, Error, TEXT("OnConnected %s"), *Info);
 }


 void UWebSocketTest::OnClosed(int32 StatusCode, const FString &Reason, bool bWasClean)
 {
	 UE_LOG(LogTemp, Error, TEXT("OnClosed %s,%d"),*Reason, StatusCode);
 }

 void UWebSocketTest::OnMessage(const FString &MessageStr)
 {
	 UE_LOG(LogTemp, Error, TEXT("OnMessage %s"), *MessageStr);
 }
