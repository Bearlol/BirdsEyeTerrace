// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "BETCharacter.h"
#include "BETGameMode.generated.h"

UCLASS(minimalapi)
class ABETGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ABETGameMode();

	UPROPERTY(EditDefaultsOnly)
		TArray<TSubclassOf<ABETCharacter>> CharacterToSpawn;

	virtual UClass* GetDefaultPawnClassForController_Implementation (AController* InController) override;
};



