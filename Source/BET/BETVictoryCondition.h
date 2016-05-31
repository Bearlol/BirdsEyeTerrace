// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BETInteractable.h"
#include "BETCharacter.h"
#include "BETVictoryCondition.generated.h"

/**
 * 
 */
UCLASS()
class BET_API ABETVictoryCondition : public ABETInteractable
{
	GENERATED_BODY()

		ABETVictoryCondition();

protected:
	virtual void Interact() override;
	UFUNCTION()
		virtual void OnOverlap(AActor* OtherActor);
	

public:
	ABETCharacter* Character;
};
