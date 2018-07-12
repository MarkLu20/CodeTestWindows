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

	/*设置频道属性(setChannelProfile)
		CHANNEL_PROFILE_COMMUNICATION	通信为默认模式，用于常见的一对一或群聊，频道中的任何用户可以自由说话
		CHANNEL_PROFILE_LIVE_BROADCASTING 直播模式有主播和观众两种用户角色，可以通过调用 setClientRole 设置。主播可收发语音和视频，但观众只能收，不能发
		CHANNEL_PROFILE_GAME 频道内任何用户可自由发言。该模式下默认使用低功耗低码率的编解码器*/
	UFUNCTION(BlueprintCallable, Category = "AgoraVoice")
		int SetChanelProfile(ECHANNEL_PROFILE_TYPE ChannelProfile=ECHANNEL_PROFILE_TYPE::CHANNEL_PROFILE_COMMUNICATION);
	/*打开音频 默认是打开的*/
	UFUNCTION(BlueprintCallable, Category = "AgoraVoice")
		int EnableAudio();
	/*关闭音频*/
	UFUNCTION(BlueprintCallable, Category = "AgoraVoice")
		int DisableAudio();
	/*设置音质(setAudioProfile)*/
	UFUNCTION(BlueprintCallable, Category = "AgoraVoice")
		int SetAudioProfile(EAUDIO_PROFILE_TYPE	AudioProfile=EAUDIO_PROFILE_TYPE::AUDIO_PROFILE_DEFAULT, EAUDIO_SCENARIO_TYPE AudioScenario=EAUDIO_SCENARIO_TYPE::AUDIO_SCENARIO_DEFAULT);
	/*加入房间*/

		/*参数	     描述
		token        默认已经设置为null
		channelId    标识通话的频道名称，长度在64字节以内的字符串。以下为支持的字符集范围（共89个字符） : a - z, A - Z, 0 - 9, space, !#$%&, () + , -, :; <= .#$%&, () + , -, :; <= ., > ? @[], ^_, { | }, ~
		info         默认设置为空
		uid          默认为0 (非必选项) 用户ID，32位无符号整数。建议设置范围：1到(2 ^ 32 - 1)，并保证唯一性。
		             如果不指定（即设为0），SDK 会自动分配一个，并在 onJoinChannelSuccess 回调方法中返回，App 层必须记住该返回值并维护，
		             SDK不对该返回值进行维护 uid 在 SDK 内部用 32 位无符号整数表示，
		             由于 Java 不支持无符号整数，uid 被当成 32 位有符号整数处理，对于过大的整数，Java 会表示为负数，如有需要可以用(uid & 0xffffffffL)转换成 64 位整数*/

	UFUNCTION(BlueprintCallable, Category = "AgoraVoice")
		int JoinChannel(const FString ChannelID,const FString Info= TEXT(""),int32 uid=0,const FString Token = TEXT("null") );
	/*离开房间*/
	UFUNCTION(BlueprintCallable, Category = "AgoraVoice")
		int LeaveChannel();
	UFUNCTION(BlueprintCallable, Category = "AgoraVoice")
		int SetEffectVolume(int volume);
	/*将自己静音 */
	/*参数  描述
	mute  bool类型 true麦克风静音 false 麦克风取消静音*/
	UFUNCTION(BlueprintCallable, Category = "AgoraVoice")
		int MuteLocalAudioStream(bool mute);
	/*静音所有远端音频*/
	/*参数  描述
      mute  true 静音所有远端的用户  false 取消静音远端的所有的客户*/
	UFUNCTION(BlueprintCallable, Category = "AgoraVoice")
		int MuteAllRemoteAudioStreams(bool mute);
	/*静音指定用户音频
		参数  描述
		uid    指定用户 ID
		muted  true 停止接收和播放指定音频流 false 允许接收和播放指定音频流*/
	UFUNCTION(BlueprintCallable, Category = "AgoraVoice")
		int MuteRemoteAudioStream(int32 uid, bool mute);
private:
	IRtcEngine *RtcEngineInstance = nullptr;
	//IRtcEngineParameter *RtcEngineParameter = nullptr;
TSharedPtr<RtcEngineParameters> RtcEngineParameter;
		int CreateAgoraRtcEngine();
		class UAgoraVoiceCallBack *CallBackInstance;
	
	
	
};
