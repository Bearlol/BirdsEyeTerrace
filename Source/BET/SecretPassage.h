// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InteractableDoor.h"
#include "BETCharacter.h"
#include "SecretPassage.generated.h"

/**
 * 
 */
UCLASS()
class BET_API ASecretPassage : public AInteractableDoor
{
	GENERATED_BODY()

		ASecretPassage();
	

	UPROPERTY(EditDefaultsOnly, Category = Mesh)
		UStaticMesh* Obstacle;

protected:

	float TimeToOpen;

public:



	virtual void Tick(float DeltaTime);

	bool IsOpen = false;

	ABETCharacter* Character;

	void OnSecret();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Secret;

	bool GetSecret();



};
