// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "ClarenceInvisibleAbility.h"
#include "CharacterClarence.h"


UClarenceInvisibleAbility::UClarenceInvisibleAbility()
	: Super()
{
	maxDuration = 10.f;
	duration = 10.f;
	Owner = Cast<ABETCharacter>(this->GetOwner());
}
/*
void UClarenceInvisibleAbility::TriggerBody()
{
	if (bIsActive == true) {

		Owner->SetActorHiddenInGame(true);
		if(Owner->GetWeapon())
			Owner->GetWeapon()->SetActorHiddenInGame(true);
	}
}*/

void UClarenceInvisibleAbility::Use()
{
	
	if (bIsActive == true) {

		Owner->SetActorHiddenInGame(true);
		if (Owner->GetWeapon())
			Owner->GetWeapon()->SetActorHiddenInGame(true);
	}

}


void UClarenceInvisibleAbility::DeactivateAbility()
{
	bIsActive = false;
	Owner->SetActorHiddenInGame(false);
	if(Owner->GetWeapon())
	Owner->GetWeapon()->SetActorHiddenInGame(false);
	duration = maxDuration;
}

void UClarenceInvisibleAbility::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (bIsActive) {
		duration -= DeltaTime;
		if (duration <= 0.f) {
			DeactivateAbility();
			duration = maxDuration;
		}
	}

}

