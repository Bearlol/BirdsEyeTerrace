// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AreaOfEffect.h"
#include "AbilityBlockAbilities.generated.h"

/**
 * 
 */
UCLASS()
class BET_API UAbilityBlockAbilities : public UAreaOfEffect
{
	GENERATED_BODY()
public:
	UAbilityBlockAbilities();
	
protected:
	virtual void UsedFunction(ABETCharacter* character) override;
	
};
