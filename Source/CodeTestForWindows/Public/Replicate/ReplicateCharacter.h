// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ReplicateCharacter.generated.h"

UCLASS()
class CODETESTFORWINDOWS_API AReplicateCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AReplicateCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	/**
	* @param RealViewer - is the "controlling net object" associated with the client for which network relevancy is being checked (typically player controller)
	* @param ViewTarget - is the Actor being used as the point of view for the RealViewer
	* @param SrcLocation - is the viewing location
	*
	* @return bool - true if this actor is network relevant to the client associated with RealViewer
	*/
	/*��д����ĺ��� �ú��������жϹ۲��� ��Ϊviewtarget*/
	virtual bool IsNetRelevantFor(const AActor* RealViewer, const AActor* ViewTarget, const FVector& SrcLocation) const override;
	/*��д���ຯ����ͬ������ */
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	/*ROLE_AutonomousProxy�Ľ�ɫ���ã�ROLE_Authority�Ľ�ɫִ�� ʵ����_Implementation��cpp*/
	UFUNCTION(Reliable, Server, WithValidation)
		void SeverCollectPickups(float value);
	UFUNCTION(BlueprintCallable, Category = "Pickups")
		void CollectPickups(float value);
	/*NotiyVarbleTest �ı�Ļص�����(NotiyVarbleTest �ı������)*/
	UFUNCTION()
		void Rep_Func();

	UPROPERTY(BlueprintReadWrite, ReplicatedUsing = Rep_Func)
		float NotiyVarbleTest;

	UPROPERTY(BlueprintReadOnly, Replicated)
		float ReplicateVar;
	UFUNCTION(BlueprintCallable)
		float GetReplicateVar();
//ROLE_Authority�Ľ�ɫ���ã����еĿͻ��˵�ROLE_AutonomousProxy�Ľ�ɫִ��,ʵ����_Implementation��cpp
	/*UFUNCTION(BlueprintCallable,Client,Unreliable)
		void ClientRPCFunction();*/  /*ûʲô�ô�*/




	//OLE_Authority�Ľ�ɫ���ò�ִ�� ���еĿͻ��˵�ROLE_AutonomousProxy,���� ROLE_SimulatedProxy �Ľ�ɫִ�У�ʵ����_Implementation��cpp
	UFUNCTION(NetMulticast, Reliable)
		void NetMulticastFunction();



	// ���縴���� �������Ϳͻ��˶�һ��һģһ�������� ���Կͻ��˷���ʲô����������ʲô
	//����������������� �ڿͻ��˷������������û�з������룩 ֻ������Ľ�ɫ�����Բ�ͬ 
	//�� ��ROLE_None��ROLE_SimulatedProxy��ROLE_AutonomousProxy��ROLE_Authority������ROLE_MAX
	/*����ͬ������������ROLE_Authority��ӵ������Կ���Ȩ �ͻ�����ROLE_SimulatedProxy������ҽ�ɫ���޷�����rpcֻ�ܱ������ܸ��Ƶ���Ϣ����ͬ���޷��޸�server�ϵ����������
		��ҽ�ɫ��ROLE_AutonomousProxy ������ROLE_SimulatedProxy�����縴�ƹ��� �������� rpc�ĺ� server �޸�server����������� ͬ��serverҲ��������client�޸�client�����������*/
	//RPC������ʵ�ֺ�����ĩβ��_Impementation


	//OLE_NONE��ʾ������󲻰��������ɫ��������ͬ��
	//ROLE_None,

	/*ROLE_SimulatedProxy��ʾ����һ��Զ�̻����ϵ�һ������Ʒ����û��Ȩ�����ı�һ�������״̬��Ҳ���ܵ���RPC�������Ȱ�RPC���Ϊ�������ñ���ȥִ�У���
		�޷�ʹ��server��Server��������ROLE_AutonomousProxy�Ľ�ɫ���ã�ROLE_Authority�Ľ�ɫִ�У� Client��Client��������ROLE_Authority�Ľ�ɫ���ã�ROLE_AutonomousProxy�Ľ�ɫִ�У�,NetMulticast,��rpc�ֻ꣬�ܱ�������ͬ����Ϣ */
	//	ROLE_SimulatedProxy,

	//	��ʾ���ȿ������ROLE_SimulatedProxy�Ĺ�������һ������Ʒ�����ֿ���ͨ��RPC���޸�����Actor��״̬��
	//	ROLE_AutonomousProxy,
	//	/** Authoritative control over the actor. */
	//	ROLE_Authority,
	//	ROLE_MAX,

	// һ�����Player��ROLE_AutonomousProxy���ɵ���rpc�� �������ROLE_SimulatedProxy��ֻ�и��ƹ��ܣ� 
};
