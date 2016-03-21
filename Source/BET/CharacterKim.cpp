// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "CharacterKim.h"


ACharacterKim::ACharacterKim()
	:Super()
{

	ActiveAbility = CreateDefaultSubobject<UAbilityMap>(TEXT("ActiveAbility"));
}

void ACharacterKim::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
		if (ActiveAbility->bIsActive == true) {
			ActiveAbility->DeactivateAbility();
		}

	}
}

void ACharacterKim::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
		if (ActiveAbility->bIsActive == true) {
			ActiveAbility->DeactivateAbility();
		}
	}

}