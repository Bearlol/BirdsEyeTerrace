// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BETInteractable.h"
#include "BETCharacter.h"
#include "BETBattery.generated.h"

/**
 * 
 */
UCLASS()
class BET_API ABETBattery : public ABETInteractable
{
	GENERATED_BODY()
		ABETBattery();
public:

		virtual void Interact() override;
		
protected:
	UFUNCTION()
	virtual void OnOverlap(AActor* OtherActor) override;
	ABETCharacter* Character;

	
	
};
