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

	//UCLASS()
	//class BET_API ABETCharacter : public ACharacter
	//{


	//public:
		//void PickUpWeapon()
		
		//	void PickUpWeapon(AWeaponPickUp* WeaponPickUp)
	//	{
		//	if (WeaponPickUp->GetWeaponClass())
			//{
				//if (CurrentWeapon)
				//{
				//	CurrentWeapon->Destroy();
				//}

				//ABETWeapon*Weapon = GetWorld()->SpawnActor<ABETWeapon>(WeaponPickUp->GetWeaponClass(), FVector, FRotator::ZeroRotator);
				//Weapon->AttachRootComponentToActor(This, TEXT("HandR"));
			//HandR will change depending on the name of the hand bone.

				//CurrentWeapon = Weapon;
		//}
	//}
	
//private:
	//ABETWeapon *CurrentWeapon;
};

