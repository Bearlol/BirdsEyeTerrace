// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "WeaponPickUp.h"



void AWeaponPickUp::OnOverlap(AActor* OtherActor)
{
	ABETCharacter* Character = Cast<ABETCharacter>(OtherActor);

	if (Character)
	{
		//Character->PickUpWeapon();
	}
}