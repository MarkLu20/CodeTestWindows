// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class CodeTestForWindows : ModuleRules
{
	public CodeTestForWindows(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore","HTTP","Json", "JsonUtilities","OnlineSubsystem","OnlineSubsystemUtils", "MXLoadingScreen" ,"Sockets","NetWorking","UMG", "SqliteSupport","AgoraVoice", "WebSockets", "OpenFireChat" });


		PrivateDependencyModuleNames.AddRange(new string[] { "Slate","SlateCore", "MXLoadingScreen" });
        DynamicallyLoadedModuleNames.AddRange(new string[] { "OnlineSubsystemNull" });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
