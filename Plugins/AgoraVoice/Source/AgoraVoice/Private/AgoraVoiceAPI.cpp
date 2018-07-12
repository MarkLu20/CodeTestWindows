// Fill out your copyright notice in the Description page of Project Settings.

#include "AgoraVoiceAPI.h"
#include  "AgoraVoiceCallBack.h"
#include "Kismet/KismetStringLibrary.h"

UAgoraVoiceAPI::UAgoraVoiceAPI(const FObjectInitializer &ObjectInitializer) :UObject(ObjectInitializer)
{
	
}

int UAgoraVoiceAPI::CreateAgoraRtcEngine()
{
	
	RtcEngineInstance = createAgoraRtcEngine();
	CallBackInstance = UAgoraVoiceCallBack::GetAgoraVoiceCBInstance();
	RtcEngineParameter = MakeShareable<RtcEngineParameters>(new RtcEngineParameters(RtcEngineInstance));
	
	 return 0;
	
}

int UAgoraVoiceAPI::Login( const FString appID)
{    
	
	RtcEngineContext rtcEngineContext;
	
	rtcEngineContext.appId = TCHAR_TO_UTF8(*appID);
	rtcEngineContext.eventHandler = CallBackInstance;
	return RtcEngineInstance->initialize(rtcEngineContext);
	
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

int UAgoraVoiceAPI::JoinChannel(const FString ChannelID, const FString Info, int32 uid, const FString Token)
{
     
	//int32 UKismetStringLibrary::Conv_StringToInt(FGuid::NewGuid().ToString());
	return RtcEngineInstance->joinChannel(TCHAR_TO_UTF8(*Token),TCHAR_TO_UTF8(*ChannelID),TCHAR_TO_UTF8(*Info),static_cast<uid_t>(uid));
}

int UAgoraVoiceAPI::LeaveChannel()
{
	return RtcEngineInstance->leaveChannel();
}

int UAgoraVoiceAPI::SetEffectVolume(int volume)
{
	return 0;// RtcEngineInstance->au
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