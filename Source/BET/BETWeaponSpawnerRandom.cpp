// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "BETWeaponSpawnerRandom.h"


ABETWeapon* ABETWeaponSpawnerRandom::SpawnWeapon()
{
	Super::SpawnWeapon();
		random = FMath::RandRange(0, weaponsList.Num() - 1);
		return GetWorld()->SpawnActor<ABETWeapon>(weaponsList[random],
		GetActorLocation(), FRotator::ZeroRotator);
}

