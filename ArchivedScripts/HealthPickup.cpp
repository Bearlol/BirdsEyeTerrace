// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "HealthPickup.h"


void AHealthPickup::OnOverlap(AActor* OtherActor)
{
	ABETCharacter* Character = Cast<ABETCharacter>(OtherActor);

	if (Character)
	{
		Character->HealthPickup();
	}


}

