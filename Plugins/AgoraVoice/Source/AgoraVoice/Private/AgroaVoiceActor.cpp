// Fill out your copyright notice in the Description page of Project Settings.

#include "AgroaVoiceActor.h"
#include "AgoraVoiceAPI.h"

// Sets default values
AAgroaVoiceActor::AAgroaVoiceActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AVAPI = GetDefault<UAgoraVoiceAPI>();

}

// Called when the game starts or when spawned
void AAgroaVoiceActor::BeginPlay()
{
	Super::BeginPlay();
	AVAPI->Login();
	
	
}

// Called every frame
void AAgroaVoiceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int AAgroaVoiceActor::SetChanelProfile(ECHANNEL_PROFILE_TYPE ChannelProfile /*= ECHANNEL_PROFILE_TYPE::CHANNEL_PROFILE_COMMUNICATION*/)
{
	return 0;
}

int AAgroaVoiceActor::EnableAudio()
{
	return 0;
}

int AAgroaVoiceActor::DisableAudio()
{
	return 0;
}

int AAgroaVoiceActor::SetAudioProfile(EAUDIO_PROFILE_TYPE AudioProfile /*= EAUDIO_PROFILE_TYPE::AUDIO_PROFILE_DEFAULT*/, EAUDIO_SCENARIO_TYPE AudioScenario /*= EAUDIO_SCENARIO_TYPE::AUDIO_SCENARIO_DEFAULT*/)
{
	return 0;
}

int AAgroaVoiceActor::JoinChannel(const FString &ChannelID, int32 uid /*= 0*/, const FString &Token /*= TEXT("null")*/)
{
	return AVAPI->JoinChannel(ChannelID,uid);
}

int AAgroaVoiceActor::LeaveChannel()
{
	return AVAPI->LeaveChannel();
}

int AAgroaVoiceActor::SetEffectVolume(int volume)
{
	return AVAPI->SetEffectVolume(volume);
}

int AAgroaVoiceActor::MuteLocalAudioStream(bool mute)
{
	return AVAPI->MuteLocalAudioStream(mute);
}

int AAgroaVoiceActor::MuteAllRemoteAudioStreams(bool mute)
{
	return AVAPI->MuteAllRemoteAudioStreams(mute);
}

int AAgroaVoiceActor::MuteRemoteAudioStream(int32 uid, bool mute)
{
	return AVAPI->MuteRemoteAudioStream(uid,mute);
}

