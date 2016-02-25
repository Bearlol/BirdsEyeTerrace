// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "WeaponPickUp.h"
#include "BETWeaponSpawnerRandom.h"


AWeaponPickUp* ABETWeaponSpawnerRandom::SpawnWeapon()
{
	Super::SpawnWeapon();
	FActorSpawnParameters spawnParams;
		spawnParams.Owner = this;
		random = FMath::RandRange(0, weaponsList.Num() - 1);
		return GetWorld()->SpawnActor<AWeaponPickUp>(weaponsList[random],
		GetActorLocation(), FRotator::ZeroRotator, spawnParams);
		TimeToRespawn = MaxRespawnTime;
		
}

 