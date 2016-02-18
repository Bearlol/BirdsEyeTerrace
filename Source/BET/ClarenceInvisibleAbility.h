// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BETAbilityComponent.h"
#include "ClarenceInvisibleAbility.generated.h"

/**
 * 
 */
UCLASS()
class BET_API UClarenceInvisibleAbility : public UBETAbilityComponent
{
	GENERATED_BODY()
		UClarenceInvisibleAbility();
protected:
	void TriggerBody(AActor* body);
	virtual void Use() override;

	UPROPERTY(EditDefaultsOnly)
		AActor* Owner;

	virtual void DeactivateAbility() override;
};
