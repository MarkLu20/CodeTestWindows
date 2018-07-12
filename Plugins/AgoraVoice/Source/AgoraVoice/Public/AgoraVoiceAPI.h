// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include  "AgoraVoiceExtension.h"
#include "IAgoraRtcEngine.h"
#include "AgoraVoiceAPI.generated.h"
using namespace agora;
using namespace rtc;
//using namespace signaling;
/**
 * 
 */
UCLASS()
class AGORAVOICE_API UAgoraVoiceAPI : public UObject
{
	GENERATED_BODY()
public:
	UAgoraVoiceAPI(const FObjectInitializer &ObjectInitializer);
	UFUNCTION(BlueprintCallable, Category = "AgoraVoice")
		int Login(const FString appID);

	/*����Ƶ������(setChannelProfile)
		CHANNEL_PROFILE_COMMUNICATION	ͨ��ΪĬ��ģʽ�����ڳ�����һ��һ��Ⱥ�ģ�Ƶ���е��κ��û���������˵��
		CHANNEL_PROFILE_LIVE_BROADCASTING ֱ��ģʽ�������͹��������û���ɫ������ͨ������ setClientRole ���á��������շ���������Ƶ��������ֻ���գ����ܷ�
		CHANNEL_PROFILE_GAME Ƶ�����κ��û������ɷ��ԡ���ģʽ��Ĭ��ʹ�õ͹��ĵ����ʵı������*/
	UFUNCTION(BlueprintCallable, Category = "AgoraVoice")
		int SetChanelProfile(ECHANNEL_PROFILE_TYPE ChannelProfile=ECHANNEL_PROFILE_TYPE::CHANNEL_PROFILE_COMMUNICATION);
	/*����Ƶ Ĭ���Ǵ򿪵�*/
	UFUNCTION(BlueprintCallable, Category = "AgoraVoice")
		int EnableAudio();
	/*�ر���Ƶ*/
	UFUNCTION(BlueprintCallable, Category = "AgoraVoice")
		int DisableAudio();
	/*��������(setAudioProfile)*/
	UFUNCTION(BlueprintCallable, Category = "AgoraVoice")
		int SetAudioProfile(EAUDIO_PROFILE_TYPE	AudioProfile=EAUDIO_PROFILE_TYPE::AUDIO_PROFILE_DEFAULT, EAUDIO_SCENARIO_TYPE AudioScenario=EAUDIO_SCENARIO_TYPE::AUDIO_SCENARIO_DEFAULT);
	/*���뷿��*/

		/*����	     ����
		token        Ĭ���Ѿ�����Ϊnull
		channelId    ��ʶͨ����Ƶ�����ƣ�������64�ֽ����ڵ��ַ���������Ϊ֧�ֵ��ַ�����Χ����89���ַ��� : a - z, A - Z, 0 - 9, space, !#$%&, () + , -, :; <= .#$%&, () + , -, :; <= ., > ? @[], ^_, { | }, ~
		info         Ĭ������Ϊ��
		uid          Ĭ��Ϊ0 (�Ǳ�ѡ��) �û�ID��32λ�޷����������������÷�Χ��1��(2 ^ 32 - 1)������֤Ψһ�ԡ�
		             �����ָ��������Ϊ0����SDK ���Զ�����һ�������� onJoinChannelSuccess �ص������з��أ�App ������ס�÷���ֵ��ά����
		             SDK���Ը÷���ֵ����ά�� uid �� SDK �ڲ��� 32 λ�޷���������ʾ��
		             ���� Java ��֧���޷���������uid ������ 32 λ�з��������������ڹ����������Java ���ʾΪ������������Ҫ������(uid & 0xffffffffL)ת���� 64 λ����*/

	UFUNCTION(BlueprintCallable, Category = "AgoraVoice")
		int JoinChannel(const FString ChannelID,const FString Info= TEXT(""),int32 uid=0,const FString Token = TEXT("null") );
	/*�뿪����*/
	UFUNCTION(BlueprintCallable, Category = "AgoraVoice")
		int LeaveChannel();
	UFUNCTION(BlueprintCallable, Category = "AgoraVoice")
		int SetEffectVolume(int volume);
	/*���Լ����� */
	/*����  ����
	mute  bool���� true��˷羲�� false ��˷�ȡ������*/
	UFUNCTION(BlueprintCallable, Category = "AgoraVoice")
		int MuteLocalAudioStream(bool mute);
	/*��������Զ����Ƶ*/
	/*����  ����
      mute  true ��������Զ�˵��û�  false ȡ������Զ�˵����еĿͻ�*/
	UFUNCTION(BlueprintCallable, Category = "AgoraVoice")
		int MuteAllRemoteAudioStreams(bool mute);
	/*����ָ���û���Ƶ
		����  ����
		uid    ָ���û� ID
		muted  true ֹͣ���պͲ���ָ����Ƶ�� false ������պͲ���ָ����Ƶ��*/
	UFUNCTION(BlueprintCallable, Category = "AgoraVoice")
		int MuteRemoteAudioStream(int32 uid, bool mute);
private:
	IRtcEngine *RtcEngineInstance = nullptr;
	//IRtcEngineParameter *RtcEngineParameter = nullptr;
TSharedPtr<RtcEngineParameters> RtcEngineParameter;
		int CreateAgoraRtcEngine();
		class UAgoraVoiceCallBack *CallBackInstance;
	
	
	
};
