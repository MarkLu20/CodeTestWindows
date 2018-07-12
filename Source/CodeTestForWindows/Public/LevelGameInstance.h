// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/GameEngine.h"
#include "EngineGlobals.h"
#include "SceneManagerActor.h"
#include "MXLoadingScreen/Public/MXLoadingScreen.h"
#include "Package.h"
#include "SqliteSupport.h"
#include "LevelGameInstance.generated.h"

/**
 * 
 */
 
UCLASS()
class CODETESTFORWINDOWS_API ULevelGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
		

		ULevelGameInstance(/*const FObjectInitializer &ObjectInializer*/);

		virtual void Init() override;

public:
	FLoadPackageAsyncDelegate _tmpDelegate;
	

	void LoadingCallBack(const FName& _packageName, const TArray<FName>& _allLevelNames, const TArray<FName>& _loadedLevelNames, float _percent);
	UFUNCTION(BlueprintCallable)
	void OpenLevel();
	void LoadAsyncCB(const FName &Name,UPackage *Package,EAsyncLoadingResult::Type Result);
	void OnAssetLoadedFunc(UObject *LoadedObject);
	void LoadOver();
	void ReviceMapName(const FString &MapName);
	void EndMap(UWorld *World);
   UFUNCTION(BlueprintCallable)
	void ShowLoadingScreen();
   void DirtyPackage(UPackage *Package);
   UFUNCTION(BlueprintCallable)
   void FindAllUStruct();
   UFUNCTION(BlueprintCallable)
	   void MixScreen();
	float	LastLoadIndex;
	float StreamingArrayNum;
	float loadtime = 0;
private:
	TArray<class ULevelStreaming *> StreamingArray;
	int32 Index;
	bool HasLoaded(FName PackageName);
	//TSharedPtr < SMXLoadingScreenWidget >LoadingScreenWidget;
};
