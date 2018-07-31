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
	UAgoraVoiceManager(const FObjectInitializer &ObjectInitializer);
	~UAgoraVoiceManager();
	static UAgoraVoiceManager *GetVoiceManager();
	UFUNCTION(BlueprintCallable)
		void Login(const FString Appid);
	UFUNCTION(BlueprintCallable)
		int JoinChannel(const FString RoomName);
	void ReleaseRtcEgine();
	TWeakObjectPtr< UAgoraVoiceAPI> API;
private:
	 UAgoraVoiceAPI *VoiceAPI;
	 
	UAgoraVoiceCallBack *VoiceCallBack;
	static UAgoraVoiceManager *VoiceManager;

};
