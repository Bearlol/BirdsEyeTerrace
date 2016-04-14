// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "BETWeaponSpawnerSpecific.h"

AWeaponPickUp* ABETWeaponSpawnerSpecific::SpawnWeapon()
{
	Super::SpawnWeapon();
	return GetWorld()->SpawnActor<AWeaponPickUp>(WeaponClass,
		GetActorLocation(), FRotator::ZeroRotator);
}


