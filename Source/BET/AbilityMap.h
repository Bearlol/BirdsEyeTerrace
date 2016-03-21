// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BETAbilityComponent.h"
#include "BETCharacter.h"
#include "AbilityMap.generated.h"

/**
 * 
 */
UCLASS()
class BET_API UAbilityMap : public UBETAbilityComponent
{
	GENERATED_BODY()
		UAbilityMap();
protected:
	//void TriggerBody();
	virtual void Use() override;
	ABETCharacter* Owner;
	virtual void DeactivateAbility() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	
	
};
