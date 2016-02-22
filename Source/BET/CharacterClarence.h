// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BETCharacter.h"
#include "ClarenceInvisibleAbility.h"
#include "CharacterClarence.generated.h"

/**
 * 
 */
UCLASS()
class BET_API ACharacterClarence : public ABETCharacter
{
	GENERATED_BODY()
		ACharacterClarence();
		UPROPERTY(EditDefaultsOnly)
		class UStaticMesh* clarenceMesh;

protected:
	virtual void MoveForward(float Val) override;
	virtual void MoveRight(float Val) override;
};
