// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BETWeaponSpawner.h"
#include "BETWeaponSpawnerRandom.generated.h"

/**
 * 
 */
UCLASS()
class BET_API ABETWeaponSpawnerRandom : public ABETWeaponSpawner
{
	GENERATED_BODY()
	
protected: 
	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<ABETWeapon>> weaponsList;
	UPROPERTY(EditDefaultsOnly)
		uint16 random;
	

	
protected:
	virtual ABETWeapon* SpawnWeapon() override;
	
};
