// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BETWeaponSpawner.h"
#include "WeaponPickUp.h"
#include "BETWeaponSpawnerSpecific.generated.h"

/**
 * 
 */
UCLASS()
class BET_API ABETWeaponSpawnerSpecific : public ABETWeaponSpawner
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AWeaponPickUp> WeaponClass;

protected:
	virtual AWeaponPickUp* SpawnWeapon() override;
		
};
//TArray<TSubclassOf<BETWeapon>
//research FMath::RandRange(0, Array.Num() - 1)