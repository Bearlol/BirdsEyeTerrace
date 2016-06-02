// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BETInteractable.h"
#include "BETCharacter.h"
#include "SecretPassage.h"
#include "SecretSwitch.generated.h"

/**
 * 
 */
UCLASS()
class BET_API ASecretSwitch : public ABETInteractable
{
	GENERATED_BODY()

		ASecretSwitch();


	UPROPERTY(EditDefaultsOnly, Category = Mesh)
		UStaticMesh* Switch;
	
protected:

	bool IsInteracted = false;
	
	ASecretPassage* GetSecret;

public:

	virtual void Interact() override;

	UFUNCTION()
		virtual void OnOverlap(AActor* OtherActor);

	ABETCharacter* Character;
};
