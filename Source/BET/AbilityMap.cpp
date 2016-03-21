// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "AbilityMap.h"
#include "CharacterKim.h"

UAbilityMap::UAbilityMap()
	: Super()
{

	Owner = Cast<ABETCharacter>(this->GetOwner());

}

void UAbilityMap::Use()

{
	Super::Use();
}


void UAbilityMap::DeactivateAbility()
{

}

void UAbilityMap::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{

}


