// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "ClarenceInvisibleAbility.h"


UClarenceInvisibleAbility::UClarenceInvisibleAbility()
	: Super()
{
	Owner = this->GetOwner();
}

void UClarenceInvisibleAbility::TriggerBody(AActor* body)
{

	body->SetActorHiddenInGame(true);

}

void UClarenceInvisibleAbility::Use()
{
	
	TriggerBody(Owner);

}



