// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "AESTest.generated.h"

/**
 *
 */
UCLASS()
class CODETESTFORWINDOWS_API UAESTest : public UObject
{
	GENERATED_BODY()
private:
	/*��Կ ���ܽ��ܵ���Կ ���ܺͽ�����Ҫ��ͬ������Կ���ԳƼ��ܣ�*/
	/*��Ҫ32λ�����ַ�*/
	static FString PrivateKey;
	/*�и��ַ�����ʶ�� ���һ���ǿո�*/
     FString Sysmpol;
	static UAESTest *AESInstance;
	/*��ȡʱ����������*/
	FString GetKeys(FString RawDataNum);
	/*������Կ*/
	FString CreateKey(FString Keys);
	/*���ɾ�̬��Կ*/
	FString CreateStaticKey();
	/*ת��FString��Base64//��ת��Tarray<uint8>*/
	FString FStringToBase64(FString RawData);
	/*ת��Base64��FString//��ת��Tarray<uint8>*/
	FString Base64ToFString(FString Base64Data, FString Keys);
	FString Encrypt(FString Data, FString Keys);
	/*����*/
	FString Decrypt(FString Aes, FString Keys);
	/*��ӷָ���/ʹ�÷ָ�����ȡԴ����*/
	FString ConvertCode(FString CodeData, bool isEncryption);
public:
	/*��ȡ����*/
	UFUNCTION(BlueprintCallable, Category = AES)
		static UAESTest *GetAesInstance();
	/*��̬����*/
	UFUNCTION(BlueprintCallable)
		void EncryDataStatic(FString RawData,FString &Aes,int&RawDataUseLen);
	/*����*/
	UFUNCTION(BlueprintCallable)
		void EncryptData(FString RawData,FString &AES,FString &Keys);
	/*����*/
	UFUNCTION(BlueprintCallable)
		void DecryptData(FString Aes,FString Keys,FString &RawData);
	UFUNCTION(BlueprintCallable)
		static FString Encrypt(FString Contents);
	FString Decrypt(FString Contents);
	FString teststr = "eeeeee";

};
