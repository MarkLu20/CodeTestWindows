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
	static FString Sysmpol;
public:
	UFUNCTION(BlueprintCallable)
		static FString Encrypt(FString Contents);
	FString Decrypt(FString Contents);
	FString teststr = "eeeeee";

};
