// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BETInteractable.h"
#include "BETCharacter.h"
#include "Components/ActorComponent.h"
#include "InteractableDoor.generated.h"

/**
 * 
 */
UCLASS()
class BET_API AInteractableDoor : public ABETInteractable
{
	GENERATED_BODY()


protected:


	AInteractableDoor();
	float TimeToOpen;

	bool IsInteracted = false;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Locked = false;
public:
	virtual void Interact() override;

	bool IsOpen = false;

	virtual void Tick( float DeltaTime);
	
	ABETCharacter* Character;

	UFUNCTION()
		virtual void OnOverlap(AActor* OtherActor);
};
