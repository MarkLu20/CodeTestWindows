// Fill out your copyright notice in the Description page of Project Settings.

#include "WebSocketTestActor.h"
#include "Engine.h"
#include "Runtime/Online/WebSockets/Public/WebSocketsModule.h"
#include "Runtime/Online/WebSockets/Public/IWebSocketsManager.h"
#include "Runtime/Online/WebSockets/Public/IWebSocket.h"
#include "ModuleManager.h"

// Sets default values
AWebSocketTestActor::AWebSocketTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWebSocketTestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWebSocketTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWebSocketTestActor::TestWebSocket()
{
	testWeb = GetDefault<UWebSocketTest>();
	TArray<FString> TestWebStr;
	//TestWebStr.Add(TEXT("ws"));
	//TestWebStr.Add(TEXT("wss"));
	//TestWebStr.Add(TEXT("v10.stomp"));
	//TestWebStr.Add(TEXT("v11.stomp"));
	TestWebStr.Add("Protocol");
	TestWebStr.Add("Protocol-v2");
	//testWeb->CreateWebScoket(FString("wss://echo.websocket.org"),TestWebStr);
	FString url = FString(TEXT("ws://192.168.2.13:8081/websocket"));
	//testWeb->Closeoncet(url,TestWebStr);

	testWeb->CreateWebScoket(url, TestWebStr);
}

