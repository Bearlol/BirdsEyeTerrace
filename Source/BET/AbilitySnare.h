// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AreaOfEffect.h"
#include "AbilitySnare.generated.h"

/**
 * 
 */
UCLASS()
class BET_API UAbilitySnare : public UAreaOfEffect
{
	GENERATED_BODY()
	
	
	
public:
	UAbilitySnare();

protected:
	virtual void UsedFunction(ABETCharacter* character) override;
};
