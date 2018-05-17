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
	/*密钥 加密解密的密钥 加密和解密需要用同样的密钥（对称加密）*/
	/*需要32位以上字符*/
	static FString PrivateKey;
	/*切割字符串标识符 最后一个是空格*/
	static FString Sysmpol;
public:
	UFUNCTION(BlueprintCallable)
		static FString Encrypt(FString Contents);
	FString Decrypt(FString Contents);
	FString teststr = "eeeeee";

};
