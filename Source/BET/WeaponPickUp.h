// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PickUp.h"
#include "BETCharacter.h"
#include "WeaponPickUp.generated.h"

/**
 * 
 */

UENUM ()
enum EWeaponTypes
{
	WEAPON_NONE,
	WEAPON_AXE
	// need to add all weapons
};






UCLASS()
class BET_API AWeaponPickUp : public APickUp
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, Category = PickUp)
		TEnumAsByte<EWeaponTypes> WeaponType;

	//UPROPERTY(EditAnywhere, Category = PickUp)
		//TSubclassOf<ABETWeapon> WeaponClass;
	// better for a more flexable way to code it

	virtual void OnOverlap(AActor* OtherActor) override;
	
	
};
