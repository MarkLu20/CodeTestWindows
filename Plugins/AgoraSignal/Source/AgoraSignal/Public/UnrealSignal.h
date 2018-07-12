// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <stdio.h>
#include <string.h>
#include "agora_sig.h"
#include "UObject/NoExportTypes.h"
#include "Runtime/Engine/Public/Tickable.h"
#include "UnrealSignal.generated.h"
using namespace agora_sdk_win;

/**
 *
 */
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReconnecting,int32,nretry);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReconnected,int32,fd);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLoginsuccess,int32,uid,int,fd);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLogin,int,Ecode);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLoginOut, int, Ecode);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLoginFailed,int,Ecode);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnChannelJoined,const FString ,ChannelId,int32,ChannelIdSize);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnChannelLeaved, const FString, ChannelId, int32, ChannelIdSize);
//
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMessageSendSuccess,const FString,MessageID,int32,MessageIDSize);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FOnMessageInstantReceive,const FString,Accout,int32,AccountSize,int32,uid,const FString,Msg,int32,MsgSize);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_SevenParams(FOnMessageChannelReceive,const FString,ChannelID,int32,ChannelIDSize,const FString,Account,int32,AccountSize,int32,uid,const FString,Msg,int32,MsgSize);
//
UCLASS(Blueprintable)
class AGORASIGNAL_API UUnrealSignal : public UObject, public FTickableGameObject
{
	GENERATED_BODY()
public:
	UUnrealSignal(const FObjectInitializer& ObjectInitializer);
	~UUnrealSignal();

	// ͨ�� FTickableGameObject �̳�
	virtual void Tick(float DeltaTime) override;

	virtual bool IsTickable() const override;

	virtual TStatId GetStatId() const override;
	//��ȡUnrealSignalʵ��
	UFUNCTION(BlueprintCallable, Category = "Agora")
		static UUnrealSignal *GetUnrealSignalInstance();
	//��ȡAgoraAPIʵ��
	UFUNCTION(BlueprintCallable, Category = "Agora")
		void GetAgroaInstance(const FString AppID);
	//���ûص�����
	UFUNCTION(BlueprintCallable, Category = "Agora")
		void CallBackSet(class UCallBack *callBack);
	//��¼����ϵͳ
	UFUNCTION(BlueprintCallable, Category = "Agora")
		void Login(const FString AppID,  const FString Account, const FString Token,  int32 uid, const FString DeviceID);
	//�ǳ�����ϵͳ
	UFUNCTION(BlueprintCallable, Category = "Agora")
		void LoginOut();
	//���͵�Ե���Ϣ (messageInstantSend)
	//�÷������͵�Ե���Ϣ��ĳ��ָ���˺š� ���ͳɹ����ؽ��ص� onMessageSendSuccess��
	//�Է����յ� onMessageInstantReceive �ص��� ����ʧ�ܽ��ص� onMessageSendError��
	UFUNCTION(BlueprintCallable, Category = "Agora")
		void MessageInstanSend(const FString account, int uid, const FString Msg, const FString MsgID);
	//��ѯ�û�״̬ (queryUserStatus)
		//�÷������ڲ�ѯ�û��Ƿ����ߡ����óɹ������� onQueryUserStatusResult �ص���
	UFUNCTION(BlueprintCallable, Category = "Agora")
		void QureyUserStatus(const FString Account);
	//����Ƶ�� (channelJoin)
	//�÷������û�����ָ��Ƶ�����û�һ��ֻ�ܼ���һ��Ƶ���������ָ��Ƶ��ʱ��������Ƶ���У����Զ�������Ƶ���˳��� 
	//�û�����Ƶ���ɹ����Լ����յ��ص� onChannelJoined������ͬһƵ�����û����յ��ص� onChannelUserJoined��
	//�û�����ʧ�ܺ��Լ����յ��ص� onChannelJoinFailed��
	UFUNCTION(BlueprintCallable, Category = "Agora")
		void ChannelJoin(const FString ChannelID);
	UFUNCTION(BlueprintCallable, Category = "Agora")
		void ChanelLeave(const FString ChanelID);
	//��ѯƵ���û��� (channelQueryUserNum)
	UFUNCTION(BlueprintCallable, Category = "Agora")
		void ChannelQueryUserNum(const FString ChannelID);
	//����Ƶ����Ϣ (messageChannelSend)
	//�÷������ڷ���Ƶ����Ϣ��Ƶ�������г�Ա���յ� onMessageChannelReceive �ص��� ���ͳɹ���ص� onMessageSendSuccess������ʧ�ܻ�ص� onMessageSendError��
	UFUNCTION(BlueprintCallable, Category = "Agora")
		void MessgeChannelSend(const FString ChannelID,const FString Msg,const FString MsgID);
	//������� (channelInviteUser)
	//����յ��Է���ȷ����Ϣ�����ؽ��ص� onInviteReceivedByPeer, �Է���ص� onInviteReceived��
	UFUNCTION(BlueprintCallable, Category = "Agora")
		void ChannelInviteUser(const FString ChannelID,const FString Account,int uid);
	UFUNCTION(BlueprintCallable, Category = "JsonTool")
		TArray<FString>  LoadAccount(FString Path);
	/*UPROPERTY(BlueprintAssignable, Category = "Agora")
		FOnReconnecting OnReconnecting;
	UPROPERTY(BlueprintAssignable, Category = "Agora")
		FOnReconnected OnReconnected;
	UPROPERTY(BlueprintAssignable, Category = "Agora")
		FOnLoginsuccess OnLoginsuccess;
	UPROPERTY(BlueprintAssignable, Category = "Agora")
		FOnLogin OnLogin;
	UPROPERTY(BlueprintAssignable, Category = "Agora")
		FOnLoginFailed OnLoginFailed;
	UPROPERTY(BlueprintAssignable, Category = "Agora")
		FOnChannelJoined OnChannelJoined;
	UPROPERTY(BlueprintAssignable, Category = "Agora")
		FOnChannelLeaved OnChannelLeaved;
	UPROPERTY(BlueprintAssignable, Category = "Agora")
		FOnMessageSendSuccess OnMessageSendSuccess;
	UPROPERTY(BlueprintAssignable, Category = "Agora")
		FOnMessageInstantReceive OnMessageInstantReceive;
	UPROPERTY(BlueprintAssignable, Category = "Agora")
		FOnMessageChannelReceive OnMessageChannelReceive;
	UPROPERTY(BlueprintAssignable, Category = "Agora")
        FOnLoginOut OnLoginOut;*/
	UFUNCTION(BlueprintCallable, Category = "Agora")
		void Test(int32 t);
private:
	static UUnrealSignal *USInstance;
	 IAgoraAPI *AgoraInstance= nullptr;
	
};



