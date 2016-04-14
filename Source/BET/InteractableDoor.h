// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BETInteractable.h"
#include "InteractableDoor.generated.h"

/**
 * 
 */
UCLASS()
class BET_API AInteractableDoor : public ABETInteractable
{
	GENERATED_BODY()

		AInteractableDoor();

protected:

	float TimeToOpen;

	bool IsInteracted = false;
	bool IsOpen = false;
	virtual void Tick(float DeltaTime) override;
		
	virtual void Interact() override;
};
