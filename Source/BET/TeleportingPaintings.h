// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BETInteractable.h"
#include "BETCharacter.h"
#include "TeleportingPaintings.generated.h"

/**
 * 
 */
UCLASS()
class BET_API ATeleportingPaintings : public ABETInteractable
{
	GENERATED_BODY()
	
public:
	ATeleportingPaintings();
	virtual void Interact() override;

protected:
	UFUNCTION()
		virtual void OnOverlap(AActor* OtherActor);
public:
	UPROPERTY(EditInstanceOnly)
		AActor* TargetLocation;

	ABETCharacter* Character;	
};
