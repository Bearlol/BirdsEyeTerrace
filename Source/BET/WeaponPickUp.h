// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PickUp.h"
#include "BETCharacter.h"
#include "WeaponPickUp.generated.h"

/**
 * 
 */







UCLASS()

class BET_API AWeaponPickUp : public APickUp
{
	GENERATED_BODY()

public:
	TSubclassOf<ABETWeapon>GetWeaponClass(){ return WeaponClass; }

protected:


	UPROPERTY(EditAnywhere, Category = PickUp)
		TSubclassOf<ABETWeapon> WeaponClass;
	// better for a more flexable way to code it

	virtual void OnOverlap(AActor* OtherActor) override;

};

