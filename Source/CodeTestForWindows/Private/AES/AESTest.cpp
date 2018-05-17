// Fill out your copyright notice in the Description page of Project Settings.
#include "AESTest.h"
#include "AES.h"
#include "string"
FString UAESTest::PrivateKey = TEXT("***************************&&&&&&&&&&&&&&&");
FString  UAESTest::Sysmpol = TEXT("你好啊 ");
FString UAESTest::Encrypt(FString Contents)
{
	FString content = TEXT("eeeee");
	std::string stdstr = "走啊资源啊afsadf";
	FString fstr = UTF8_TO_TCHAR(stdstr.data());
	Contents.Append(Sysmpol);
	uint8* Blob = nullptr;
	uint32 Size;
	Size = Contents.Len();
	Size = Size + (FAES::AESBlockSize - (Size % FAES::AESBlockSize));
	Blob = new uint8[Size];
	StringToBytes(Contents,Blob,Size);
	//加密
	FAES::EncryptData(Blob,Size,TCHAR_TO_ANSI(*PrivateKey));
	FString EncryptString = FString::FromHexBlob(Blob,Size);
	return EncryptString;
}

FString UAESTest::Decrypt(FString Contents)
{
	return FString();
}
