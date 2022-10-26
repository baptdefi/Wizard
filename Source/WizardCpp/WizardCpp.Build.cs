// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WizardCpp : ModuleRules
{
	public WizardCpp(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG" });
	}
}
