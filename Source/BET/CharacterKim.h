// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BETCharacter.h"
#include "AbilityMap.h"
#include "CharacterKim.generated.h"

/**
 * 
 */
UCLASS()
class BET_API ACharacterKim : public ABETCharacter
{
	GENERATED_BODY()
		ACharacterKim();
protected:
	virtual void MoveForward(float Val) override;
	virtual void MoveRight(float Val) override;

};
