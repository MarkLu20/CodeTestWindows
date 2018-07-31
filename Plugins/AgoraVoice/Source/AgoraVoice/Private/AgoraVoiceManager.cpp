// Fill out your copyright notice in the Description page of Project Settings.
#include "AgoraVoiceManager.h"
#include "AgoraVoiceAPI.h"
#include "AgoraVoiceCallBack.h"



UAgoraVoiceManager *UAgoraVoiceManager::VoiceManager = nullptr;
UAgoraVoiceManager::UAgoraVoiceManager(const FObjectInitializer &ObjectInitializer)
{
	VoiceAPI = NewObject<UAgoraVoiceAPI>();
	API= NewObject<UAgoraVoiceAPI>();
	VoiceAPI->AddToRoot();
	//VoiceAPI->AddToRoot();
}

UAgoraVoiceManager::~UAgoraVoiceManager()
{

}

UAgoraVoiceManager* UAgoraVoiceManager::GetVoiceManager()
{
	if (VoiceManager==nullptr)
	{
		VoiceManager = NewObject<UAgoraVoiceManager>();
		VoiceManager->AddToRoot();
	}
	return VoiceManager;
}

void UAgoraVoiceManager::Login(const FString Appid)
{
	VoiceAPI->CreateAgoraRtcEngine();
	VoiceAPI->Login(Appid);
	
	
}

int UAgoraVoiceManager::JoinChannel(const FString RoomName)
{
	return VoiceAPI->JoinChannel(RoomName);
}

void UAgoraVoiceManager::ReleaseRtcEgine()
{
	VoiceAPI->ReleaseRtcEgine();
}
