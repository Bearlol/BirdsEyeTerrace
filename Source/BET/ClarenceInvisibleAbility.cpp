// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "ClarenceInvisibleAbility.h"


UClarenceInvisibleAbility::UClarenceInvisibleAbility()
	: Super()
{
	maxDuration = 10.f;
	duration = 10.f;
}

void UClarenceInvisibleAbility::TriggerBody(AActor* body)
{

	body->SetActorHiddenInGame(true);

}

void UClarenceInvisibleAbility::Use()
{
	Owner = this->GetOwner();
	TriggerBody(Owner);

}


void UClarenceInvisibleAbility::DeactivateAbility()
{
	bIsActive = false;
	Owner->SetActorHiddenInGame(false);
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
	// ...
	/*
	TimeToNextUse -= DeltaTime;
	if (bIsActive)
	{
		Use();
	}
	*/
}

