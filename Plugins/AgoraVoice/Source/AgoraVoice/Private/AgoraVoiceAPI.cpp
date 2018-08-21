// Fill out your copyright notice in the Description page of Project Settings.

#include "AgoraVoiceAPI.h"
//#include <afxstr.h>
#include  "AgoraVoiceCallBack.h"
#include "Kismet/KismetStringLibrary.h"
#include <stdio.h>
#include <iostream>
using namespace std;
UAgoraVoiceAPI *UAgoraVoiceAPI::AgoraVoiceInstance = nullptr;
UAgoraVoiceAPI::UAgoraVoiceAPI(const FObjectInitializer &ObjectInitializer) :UObject(ObjectInitializer)
{
	//CallBackInstance = UAgoraVoiceCallBack::GetAgoraVoiceCBInstance();
	CallBackInstance = CreateDefaultSubobject<UAgoraVoiceCallBack>(TEXT("CallBackInstance"));
}



int UAgoraVoiceAPI::Login()
{    
	//LPCTSTR appid= "fb50b66cf43940679083c25b520192b0";
	RtcEngineInstance= (IRtcEngine *)createAgoraRtcEngine();
	RtcEngineContext rtcEngineContext;

	rtcEngineContext.appId = "c3155a998bd446f3abc0cab6a12aeabf";  //TCHAR_TO_UTF8(*appID);
	rtcEngineContext.eventHandler = CallBackInstance;
	return RtcEngineInstance->initialize(rtcEngineContext);
	
}

UAgoraVoiceAPI* UAgoraVoiceAPI::GetAgoraVoiceAPIInstance()
{
	if (AgoraVoiceInstance==nullptr)
	{
		AgoraVoiceInstance = NewObject<UAgoraVoiceAPI>();
		AgoraVoiceInstance->AddToRoot();
	}
	return AgoraVoiceInstance;
}

int UAgoraVoiceAPI::SetChanelProfile(ECHANNEL_PROFILE_TYPE ChannelProfile)
{   
	return  RtcEngineInstance->setChannelProfile(static_cast<CHANNEL_PROFILE_TYPE>(ECHANNEL_PROFILE_TYPE::CHANNEL_PROFILE_GAME));
	
}



int UAgoraVoiceAPI::EnableAudio()
{
	return RtcEngineInstance->enableAudio();
}

int UAgoraVoiceAPI::DisableAudio()
{
	return  RtcEngineInstance->disableAudio();
}

int UAgoraVoiceAPI::SetAudioProfile(EAUDIO_PROFILE_TYPE AudioProfile, EAUDIO_SCENARIO_TYPE AudioScenario)
{
	return  RtcEngineInstance->setAudioProfile(static_cast<AUDIO_PROFILE_TYPE>(AudioProfile),static_cast<AUDIO_SCENARIO_TYPE>(AudioScenario));
}

int UAgoraVoiceAPI::JoinChannel(const FString &ChannelID, int32 uid, const FString &Token)
{
	return RtcEngineInstance->joinChannel(NULL, TCHAR_TO_UTF8(*ChannelID),NULL,static_cast<uid_t>(uid));
}

int UAgoraVoiceAPI::LeaveChannel()
{
	return RtcEngineInstance->leaveChannel();
}

int UAgoraVoiceAPI::SetEffectVolume(int volume)
{
	return 0;// RtcEngineInstance->au
}

void UAgoraVoiceAPI::SaveLog(const FString & file)
{
	//RtcEngineInstance->setlogf
}

int UAgoraVoiceAPI::MuteLocalAudioStream(bool mute)
{   
	
	return RtcEngineParameter->muteLocalAudioStream(mute);
}

int UAgoraVoiceAPI::MuteAllRemoteAudioStreams(bool mute)
{
	return RtcEngineParameter->muteAllRemoteAudioStreams(mute);
}
int UAgoraVoiceAPI::MuteRemoteAudioStream(int32 uid, bool mute)
{
	return RtcEngineParameter->muteRemoteAudioStream(static_cast<uid_t>(uid),mute);
}

int32 UAgoraVoiceAPI::GetUserUID()
{
	if (Uid!=0)
	{
		return Uid;
	}
	UE_LOG(LogTemp,Error,TEXT("not joined room Success"));
	return -1;
}

void UAgoraVoiceAPI::ReleaseRtcEgine()
{
	//RtcEngineInstance->release();
}

int32 UAgoraVoiceAPI::GetFunctionCallspace(UFunction* Function, void* Parameters, FFrame* Stack)
{   
	
	UE_LOG(LogTemp,Error,TEXT("FSDAFASDF"));
	return 0;
}
