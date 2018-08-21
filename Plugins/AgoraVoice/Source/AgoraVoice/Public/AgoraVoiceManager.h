// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AgoraVoiceManager.generated.h"
class UAgoraVoiceAPI;
class UAgoraVoiceCallBack;
/**
 * UAgoraVoiceAPI
 */
UCLASS()
class AGORAVOICE_API UAgoraVoiceManager : public UObject
{
	GENERATED_BODY()
public:
	TWeakObjectPtr< UAgoraVoiceAPI> API;
	UAgoraVoiceManager(const FObjectInitializer &ObjectInitializer);
	~UAgoraVoiceManager();
	static UAgoraVoiceManager *GetVoiceManager();
	UFUNCTION(BlueprintCallable)
		void Login();
	UFUNCTION(BlueprintCallable)
		int JoinChannel(const FString &ChannelID, int32 uid = 0, const FString &Token = TEXT("null"));
	void ReleaseRtcEgine();
	void LeaveChannel();
	void EnableAudio();
	void DisableAudio(); 
	void MuteLocalAudioStream(bool mute);
	void MuteAllRemoteAudioStreams(bool mute);
	void MuteRemoteAudioStream(int32 uid, bool mute);
private:

	TWeakObjectPtr<UAgoraVoiceAPI> VoiceAPI;
	 
	UAgoraVoiceCallBack *VoiceCallBack;
	static UAgoraVoiceManager *VoiceManager;

};
