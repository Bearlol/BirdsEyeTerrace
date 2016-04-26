// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BETInteractable.h"
#include "BETCharacter.h"
#include "BETKey.generated.h"

/**
 * 
 */
UCLASS()
class BET_API ABETKey : public ABETInteractable
{
	GENERATED_BODY()

public:
	
	ABETKey();
	virtual void Interact() override;





	ABETCharacter* Character;

protected:
	UFUNCTION()
		virtual void OnOverlap(AActor* OtherActor);

};
