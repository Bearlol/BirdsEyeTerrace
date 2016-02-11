// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "ShieldPickup.h"



void AShieldPickup::OnOverlap(AActor* OtherActor)
{
	ABETCharacter* Character = Cast<ABETCharacter>(OtherActor);

	if (Character)
	{
		Character->ShieldPickup();
	}
}
