// Fill out your copyright notice in the Description page of Project Settings.

#include "AgoraVoiceAPI.h"
//#include <afxstr.h>
#include  "AgoraVoiceCallBack.h"
#include "Kismet/KismetStringLibrary.h"

UAgoraVoiceAPI::UAgoraVoiceAPI(const FObjectInitializer &ObjectInitializer) :UObject(ObjectInitializer)
{
	
}

int UAgoraVoiceAPI::CreateAgoraRtcEngine()
{
	
	CallBackInstance = NewObject<UAgoraVoiceCallBack>();
	CallBackInstance->AddToRoot();
	RtcEngineInstance = createAgoraRtcEngine();

	RtcEngineParameter = MakeShareable<RtcEngineParameters>(new RtcEngineParameters(RtcEngineInstance));
	
	 return 0;
	
}

int UAgoraVoiceAPI::Login( const FString appID)
{    
	//LPCTSTR appid= "fb50b66cf43940679083c25b520192b0";
	RtcEngineContext rtcEngineContext;

	rtcEngineContext.appId = "c3155a998bd446f3abc0cab6a12aeabf";  //TCHAR_TO_UTF8(*appID);
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
	FString test="fsdafweefwef";
	FName name = FName("eerererweryuyi");
	if (test=="fsdafweefwef")
	{
		if (name==FName("eerererweryuyi"))
		{
			test[0] = 'a';
		}
	}

	
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

void UAgoraVoiceAPI::ReleaseRtcEgine()
{
	RtcEngineInstance->release();
}

int32 UAgoraVoiceAPI::GetFunctionCallspace(UFunction* Function, void* Parameters, FFrame* Stack)
{   
	
	UE_LOG(LogTemp,Error,TEXT("FSDAFASDF"));
	return 0;
}
