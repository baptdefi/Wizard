// Copyright Epic Games, Inc. All Rights Reserved.

#include "WizardCppGameMode.h"
#include "WizardCppHUD.h"
#include "WizardCppCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWizardCppGameMode::AWizardCppGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/WizardCharacter/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AWizardCppHUD::StaticClass();
}
