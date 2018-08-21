// Fill out your copyright notice in the Description page of Project Settings.
#include "AgoraVoiceManager.h"
#include "AgoraVoiceAPI.h"
#include "AgoraVoiceCallBack.h"



UAgoraVoiceManager *UAgoraVoiceManager::VoiceManager = nullptr;
UAgoraVoiceManager::UAgoraVoiceManager(const FObjectInitializer &ObjectInitializer)
{
	VoiceAPI = GetDefault<UAgoraVoiceAPI>();
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

void UAgoraVoiceManager::Login()
{
	//VoiceAPI->CreateAgoraRtcEngine();
	VoiceAPI->Login();
	
	
}

int UAgoraVoiceManager::JoinChannel(const FString &ChannelID, int32 uid /*= 0*/, const FString &Token /*= TEXT("null")*/)
{
	return VoiceAPI->JoinChannel(ChannelID,uid,Token);
}

void UAgoraVoiceManager::ReleaseRtcEgine()
{
	VoiceAPI->ReleaseRtcEgine();
}

void UAgoraVoiceManager::LeaveChannel()
{
	VoiceAPI->LeaveChannel();
}

void UAgoraVoiceManager::EnableAudio()
{
	VoiceAPI->EnableAudio();
}

void UAgoraVoiceManager::DisableAudio()
{
	VoiceAPI->DisableAudio();
}

void UAgoraVoiceManager::MuteLocalAudioStream(bool mute)
{
	VoiceAPI->MuteLocalAudioStream(mute);
}

void UAgoraVoiceManager::MuteAllRemoteAudioStreams(bool mute)
{
	VoiceAPI->MuteAllRemoteAudioStreams(mute);
}

void UAgoraVoiceManager::MuteRemoteAudioStream(int32 uid, bool mute)
{
	VoiceAPI->MuteRemoteAudioStream(uid,mute);
}
