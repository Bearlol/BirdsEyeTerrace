// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "BET.h"
#include "GameFramework/GameState.h"
#include "BETGameMode.h"
#include "BETHUD.h"
#include "BETCharacter.h"

ABETGameMode::ABETGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ABETHUD::StaticClass();

}

UClass* ABETGameMode::GetDefaultPawnClassForController_Implementation(AController* InController)
{
	UWorld* World = GetWorld();
	AGameState* GameState = World->GetGameState();
	
	int32 Index = GameState->PlayerArray.Find(InController->PlayerState);
	if (Index < 0)
	{
		return NULL;
	}
	
	return CharacterToSpawn[Index];
}
