// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BETAbilityComponent.h"
#include "EffectOverTime.h"
#include "AreaOfEffect.generated.h"

/**
 * 
 */
UCLASS()
class BET_API UAreaOfEffect : public UBETAbilityComponent
{
	GENERATED_BODY()

		UAreaOfEffect();
public:
	
protected:
	virtual void Use() override;
	
};
