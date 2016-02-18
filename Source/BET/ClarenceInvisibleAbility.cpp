// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "ClarenceInvisibleAbility.h"


UClarenceInvisibleAbility::UClarenceInvisibleAbility()
	: Super()
{
	
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

}


