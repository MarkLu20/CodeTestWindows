// Fill out your copyright notice in the Description page of Project Settings.

#include "AgoraVoiceTestActor.h"
#include "AgoraVoiceManager.h"
#include "WebSocketTest.h"


// Sets default values
AAgoraVoiceTestActor::AAgoraVoiceTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	

}

// Called when the game starts or when spawned
void AAgoraVoiceTestActor::BeginPlay()
{
	Super::BeginPlay();
	TWeakObjectPtr<UWebSocketTest> testWeb = NewObject<UWebSocketTest>();
	TArray<FString> TestWebStr;
	TestWebStr.Add("HTTP/1.1 101");
	TestWebStr.Add("Connection:Upgrade");
	testWeb->CreateWebScoket(FString("wss://echo.websocket.org"),TestWebStr);
	//FSHA256Signature out;
	//bool test =this->SHA256(FString("fsadfsdfasdfasdf"), out);
	//UE_LOG(LogTemp,Error,TEXT("%fdsafsadf"))
	if (AvManager!=nullptr)
	{
		AvManager->ReleaseRtcEgine();

	}
	AvManager = UAgoraVoiceManager::GetVoiceManager();
	//AvManager->API.Get()->JoinChannel(FString("TestRoomfdsfd"));
	
	Mangager = NewObject<UAgoraVoiceManager>();
	
	TArray<UObject *> ReferenceObejct;
	FReferenceFinder ObjectReferenceCollector(ReferenceObejct, AvManager,false,true,true,false);
	ObjectReferenceCollector.FindReferences(AvManager);
	//TSharedPtr
	
	
	Mangager->Login(FString("fb50b66cf43940679083c25b520192b0"));
	int code = Mangager->JoinChannel(FString("TestRoomfdsfd"));
	int code1 = code;
	
}

// Called every frame
void AAgoraVoiceTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAgoraVoiceTestActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	//AvManager->ReleaseRtcEgine();
	if (EndPlayReason==EEndPlayReason::EndPlayInEditor||EndPlayReason==EEndPlayReason::Quit)
	{
		
			Mangager->ReleaseRtcEgine();
		
		
	}
}

bool AAgoraVoiceTestActor::SHA256(const FString & data, FSHA256Signature & Out)
{   
	return FGenericPlatformMisc::GetSHA256Signature(*data,static_cast<uint32>(data.GetAllocatedSize()),Out);
}

