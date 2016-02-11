// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PickUp.h"
#include "BETCharacter.h"
#include "ShieldPickup.generated.h"

/**
 * 
 */
UCLASS()
class BET_API AShieldPickup : public APickUp
{
	GENERATED_BODY()
	
	
		virtual void OnOverlap(AActor* OtherActor) override;
	
};
