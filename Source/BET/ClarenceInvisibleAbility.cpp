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


void UClarenceInvisibleAbility::Use()
	
{
	Super::Use();


		Owner->SetActorHiddenInGame(true);
		Owner->SetActorEnableCollision(false);

}


void UClarenceInvisibleAbility::DeactivateAbility()
{
	bIsActive = false;
	Owner->SetActorHiddenInGame(false);
	Owner->SetActorEnableCollision(true);
	duration = maxDuration;
}

void UClarenceInvisibleAbility::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (bIsActive) {
		duration -= DeltaTime;
		if (duration <= 0.f) {
			DeactivateAbility();
		}
	}
}

