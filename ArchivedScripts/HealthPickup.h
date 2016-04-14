// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PickUp.h"
#include "BETCharacter.h"
#include "HealthPickup.generated.h"

/**
 * 
 */
UCLASS()
class BET_API AHealthPickup : public APickUp
{
	GENERATED_BODY()
	
	
		virtual void OnOverlap(AActor* OtherActor) override;
	
};
