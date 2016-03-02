// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "CharacterClarence.h"




ACharacterClarence::ACharacterClarence()
	:Super()

{

	ActiveAbility = CreateDefaultSubobject<UClarenceInvisibleAbility>(TEXT("ActiveAbility"));
}


void ACharacterClarence::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
		if (ActiveAbility->bIsActive == true)
		ActiveAbility->DeactivateAbility();
	}
}

void ACharacterClarence::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
		if (ActiveAbility->bIsActive == true)
		ActiveAbility->DeactivateAbility();
	}

}

