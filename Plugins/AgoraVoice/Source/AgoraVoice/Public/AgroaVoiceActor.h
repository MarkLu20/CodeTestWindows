// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AgroaVoiceActor.generated.h"
class UAgoraVoiceAPI;
UCLASS()
class AGORAVOICE_API AAgroaVoiceActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAgroaVoiceActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = AgoraTest)
		int SetChanelProfile(ECHANNEL_PROFILE_TYPE ChannelProfile = ECHANNEL_PROFILE_TYPE::CHANNEL_PROFILE_COMMUNICATION);
	UFUNCTION(BlueprintCallable, Category = AgoraTest)
		int EnableAudio();
	UFUNCTION(BlueprintCallable, Category = AgoraTest)
		int DisableAudio();
	UFUNCTION(BlueprintCallable, Category = AgoraTest)
		int SetAudioProfile(EAUDIO_PROFILE_TYPE	AudioProfile = EAUDIO_PROFILE_TYPE::AUDIO_PROFILE_DEFAULT, EAUDIO_SCENARIO_TYPE AudioScenario = EAUDIO_SCENARIO_TYPE::AUDIO_SCENARIO_DEFAULT);

	UFUNCTION(BlueprintCallable, Category = AgoraTest)
		int JoinChannel(const FString &ChannelID, int32 uid = 0, const FString &Token = TEXT("null"));
	/*�뿪����*/
	UFUNCTION(BlueprintCallable, Category = AgoraTest)
		int LeaveChannel();
	UFUNCTION(BlueprintCallable, Category = AgoraTest)
		int SetEffectVolume(int volume);
	void SaveLog(const FString &file);
	/*���Լ����� */
	/*����  ����
	mute  bool���� true��˷羲�� false ��˷�ȡ������*/
	UFUNCTION(BlueprintCallable, Category = AgoraTest)
		int MuteLocalAudioStream(bool mute);

	/*��������Զ����Ƶ*/
	/*����  ����
	mute  true ��������Զ�˵��û�  false ȡ������Զ�˵����еĿͻ�*/
	UFUNCTION(BlueprintCallable, Category = AgoraTest)
		int MuteAllRemoteAudioStreams(bool mute);
	/*����ָ���û���Ƶ
	����  ����
	uid    ָ���û� ID
	muted  true ֹͣ���պͲ���ָ����Ƶ�� false ������պͲ���ָ����Ƶ��*/
	UFUNCTION(BlueprintCallable, Category = AgoraTest)
		int MuteRemoteAudioStream(int32 uid, bool mute);

private:
	TWeakObjectPtr<UAgoraVoiceAPI> AVAPI;

};
