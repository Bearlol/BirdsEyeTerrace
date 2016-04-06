// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BETAbilityComponent.h"
#include "BETCharacter.h"
#include "EffectOverTime.h"
#include "AreaOfEffect.generated.h"

/**
 * 
 */
UCLASS()
class BET_API UAreaOfEffect : public UBETAbilityComponent
{
	GENERATED_BODY()

public:
	UAreaOfEffect();
protected:
	virtual void Use() override;
	virtual void UsedFunction(ABETCharacter* character);
	
};
