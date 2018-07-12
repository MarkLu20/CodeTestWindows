// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TypeExtension.h"
#include "Tickable.h"
#include "UObject/NoExportTypes.h"
#include "Engine.h"
#include "GCloudVoice.h"
#include "SpeakerClient.generated.h"
using namespace gcloud_voice;
/**
 *
 */
UCLASS()
class MATRIXVOICE_API USpeakerClient : public UObject, public FTickableGameObject
{
	GENERATED_BODY()
public:
	 
	USpeakerClient(const FObjectInitializer &ObjectInitalizer);
	~USpeakerClient();

	UFUNCTION(BlueprintCallable, Category = "MatrixVoice")
		int32 SetAppInfo(const FString appId, const FString appKey, const FString openId);
	UFUNCTION(BlueprintCallable, Category = "MatrixVoice")
		int32 Init();
	UFUNCTION(BlueprintCallable, Category = "MatrixVoice")
		int32 SetVoiceMode(EVoiceMode Mode);
	UFUNCTION(BlueprintCallable, Category = "MatirxVoice")
		static USpeakerClient* GetSpeakerClient();
	UFUNCTION(BlueprintCallable, Category = "MatrixVoice")
		int32 JoinTeamRoom(const FString roomName,int32 TimeOut);
	UFUNCTION(BlueprintCallable, Category = "MatrixVoice")
		int32 JoinNationalRoom(const FString roomName, EVoiceMemberRole MeberRole,int32 TimeOut);
	UFUNCTION(BlueprintCallable, Category = "MatrixVoice")
		int32 QuitRoom(const FString roomName,int32 TimeOut);
	//���뷿���ں����˷� ʵʱ����ģʽ  ��ǰ��������ݼ���Ĵ󷿼䣬���ܿ������
	UFUNCTION(BlueprintCallable, Category = "MatrixVoice")
		int32 OpenMic();
	//�ر���˷� ʵʱ�������Ѽ��뷿��  ��ǰ��������ݼ���Ĵ󷿼䣬���ܿ������
	UFUNCTION(BlueprintCallable, Category = "MatrixVoice")
		int32 CloseMic();
	//��ʵʱ������ģʽ�£����뷿��ɹ��󣨰���С�������͹�ս����������Ҫ�����������ܴ�����������ݲ�����
	UFUNCTION(BlueprintCallable, Category = "MatrixVoice")
		int32 OpenSpeaker();
	//��ʵʱ������ģʽ�£����뷿��ɹ��󣨰���С�������͹�ս��������������Ҫ������������ݲ�����ʱ�����Ե��ùر���˷�ӿ�
	UFUNCTION(BlueprintCallable, Category = "MatrixVoice")
		int32 CloseSpeaker();
	//������˷�����
	UFUNCTION(BlueprintCallable, Category = "MatrixVoice")
		int32 SetMicVolume(int vol);
	//��������������
	UFUNCTION(BlueprintCallable, Category = "MatrixVoice")
		int32 SetSpeakerVolume(int vol);
	//���ûص���
	UFUNCTION(BlueprintCallable, Category = "MatrixVoice")
		int32  SetNotify(UNotify *Notify);
	//���뷿����ʼ���������
	void AddJoinedRoomName(const FString RoomName);
	//�˳��������������
	void RemoveJoinedRoomName(const FString RoomName);



		// ͨ�� FTickableGameObject �̳�
	virtual void Tick(float DeltaTime) override;

	virtual bool IsTickable() const override;

	virtual TStatId GetStatId() const override;
private:
	gcloud_voice::IGCloudVoiceEngine  *m_voiceengine = nullptr;
	 static USpeakerClient *SpeakerClient;
	 bool bRoomStatus;
	 TArray<FString> JoinedRoomName;


	

};
