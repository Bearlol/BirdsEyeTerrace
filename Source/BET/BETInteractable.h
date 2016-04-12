// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BETInteractable.generated.h"

UCLASS()
class BET_API ABETInteractable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABETInteractable();
	virtual void Interact();
protected:
	UPROPERTY(EditDefaultsOnly)
		UBoxComponent* Collider;

protected:
	UFUNCTION()
		virtual void OnOverlap(AActor* OtherActor);
//public:
//	UFUNCTION(Server, Reliable, WithValidation)
//		virtual void OnServerInteract();
};
