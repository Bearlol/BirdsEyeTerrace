// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "MyBETWeaponMelee.h"


AMyBETWeaponMelee::AMyBETWeaponMelee(const FObjectInitializer &ObjectInitializer)
	:Super(ObjectInitializer)

{

	CollisionComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Component"));
	CollisionComp -> InitCapsuleSize(5.0f,2.5f);
	CollisionComp-> BodyInstance.SetCollisionProfileName("Melee");

	//RootComponent = CollisionComp;

}





void AMyBETWeaponMelee::OnHit(AActor*OtherActor)
{
	if (OtherActor != NULL && (OtherActor != this))
	{
		UGameplayStatics::ApplyDamage(OtherActor, Damage, NULL, this, UDamageType::StaticClass());
		
	}
		
}


