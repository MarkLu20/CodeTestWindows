// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "XMPPType.h"
#include "OpenFireChatAPI.generated.h"

/**
 *
 */
class UPrivateChat;
class UMucChat;

DECLARE_MULTICAST_DELEGATE_OneParam(FGetXmppPtr, const IXmppChatPtr&);
DECLARE_MULTICAST_DELEGATE_OneParam(FJoinRoomDel, const FString&);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FReceivePrivateChatMsg, const FString&, FromUser, const FString&, ToUser, const FString&, Message, const FString&, Type,const FString&, Timetamp);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FReceiveMucChatMsg, const FString&, FromUser, const FString&, Message, const FString&, Type, const FString&, Timetamp);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FReceiveRequestJoinRoom,const FString&,FromUser,const FString&,JoinRoomName);

//class FXmppUserJid;
UCLASS()
class OPENFIRECHAT_API UOpenFireChatAPI : public UObject
{
	GENERATED_BODY()

private:



	FXmppModule *XmppModule =nullptr;

	IXmppPresencePtr XmppPresencePtr;
	
	TWeakObjectPtr< UOpenFireChatAPI>  OpenFireInstance;
	//const UOpenFireChatAPI *const test1;//���ݺ�ָ�򶼲����޸�
	//TMap<const FString&, const FString &> testMap;
	//FObjectInitializer Objectint;


public:
	UOpenFireChatAPI(const FObjectInitializer &ObjectInitializer);

	~UOpenFireChatAPI();
	//UFUNCTION(BlueprintCallable, Category = "OpenFire")
	//FORCEINLINE	static  UOpenFireChatAPI *GetOpenFireInstance();
	UFUNCTION(BlueprintCallable, Category = "OpenFire")
	void Login(FString ServerAddr, int32 ServerPort, bool bUseSSL, bool bUsePlainTextAuth, float PingInterval, float PingTimeOut, int32 MaxPingRetries, bool bPrivateChatFriendsOnly, const FString  &UserID, const FString &Auth);
	//UFUNCTION()
		/**
		*OpenFire ��¼�ɹ��Ļص�����
		*
		*�� �� ��:  OnXmppLoginComplete
		*ȫ �� ��:  UOpenFireChatAPI::OnXmppLoginComplete
		*Ȩ    ��:  public
		*��    ��:  const FXmppUserJid & UserJid
		*��    ��:  bool bWasSuccess
		*��    ��:  const FString & error
		*�� �� ֵ:  void
		*/
	void OnXmppLoginComplete(const FXmppUserJid &UserJid, bool bWasSuccess, const FString &error);
	/**
	*�Ƴ�Opnfire����
	*
	*�� �� ��:  RemoveConnection
	*ȫ �� ��:  UOpenFireChatAPI::RemoveConnection
	*Ȩ    ��:  public
	*�� �� ֵ:  void
	*/
	void RemoveConnection();
	//UFUNCTION(BlueprintCallable, Category = "OpenFire")
	FORCEINLINE	void SendPrivateMessage(const FString &FromUser, const FString &ToUser, const FString &Msg);

	FGetXmppPtr GetXmpptr;
	FDelegateHandle MucChatDelegate;
	FJoinRoomDel JoinRoomDel;
	
	TMap<FString,FString> JoinedRoomArray;
	//UPROPERTY(BlueprintAssignable, Category = "OpenFire")
	FReceivePrivateChatMsg ReceiveChatMsg;
	FReceiveMucChatMsg ReceiveMucChatMsg;
		UFUNCTION(BlueprintCallable, Category = "OpenFire")
			void CreatePublicRoom(const FString &UserName,const FString &RoomId,const FString &Passworld);
		UFUNCTION(BlueprintCallable, Category = "OpenFire")
			void JoinRoom(const FString &Room);
		UFUNCTION(BlueprintCallable, Category = "OpenFire")
			void RoomChat(const FString &UserName,const FString &RoomId,const FString &Body,const FString &ExtraInfo);
		void OnRoomChatReceived(const TSharedRef<IXmppConnection>& Connection, const FXmppRoomId& RoomId, const FXmppUserJid& UserJid, const TSharedRef<FXmppChatMessage>& ChatMsg);
		UFUNCTION(BlueprintCallable, Category = "OpenFire")
			void MucSendMessage(const FString& FromUser, const FString& Message, const FString &RoomName);
		
		void JoinRoomCall(const FString &RoomName);

public:
	TSharedPtr<IXmppConnection> xmppConnectionPtr;
	IXmppChatPtr PrivateChatPtr;
private:
	TWeakObjectPtr<UPrivateChat> PrivateChat = nullptr;
	TWeakObjectPtr<UMucChat> MucChat = nullptr;


};
