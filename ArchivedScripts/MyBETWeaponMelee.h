// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BETWeapon.h"
#include "MyBETWeaponMelee.generated.h"

/**
 * 
 */
UCLASS()
class BET_API AMyBETWeaponMelee : public ABETWeapon
{
	GENERATED_BODY()
	
protected:


	UPROPERTY(VisibleDefaultsOnly, Category = Melee)
	class UCapsuleComponent* CollisionComp;


	
public:

	AMyBETWeaponMelee(const FObjectInitializer & ObjetInitializer);

	FORCEINLINE class UCapsuleComponent* GetCollisionComp() const { return CollisionComp; }

	UFUNCTION()
		void OnHit(AActor*OtherActor);

};
