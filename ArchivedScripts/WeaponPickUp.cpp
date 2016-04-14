// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "BETWeaponSpawner.h"
#include "WeaponPickUp.h"

AWeaponPickUp::AWeaponPickUp()
	:Super() 
{

}

void AWeaponPickUp::OnOverlap(AActor* OtherActor)
{
	ABETCharacter* Character = Cast<ABETCharacter>(OtherActor);

	if (Character)
	{
		Character->PickUpWeapon(this);
		
		ABETWeaponSpawner* spawner = Cast<ABETWeaponSpawner>(GetOwner());
		spawner->WeaponPickedUp();


		Destroy();
	}
}

