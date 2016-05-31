// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "BETVictoryCondition.h"


ABETVictoryCondition::ABETVictoryCondition()
{
	Character = nullptr;
	OnActorBeginOverlap.AddDynamic(this, &ABETVictoryCondition::OnOverlap);
}

void ABETVictoryCondition::Interact()
{
	if (Character != nullptr) {
		Character->SetWin();
	}
}


void ABETVictoryCondition::OnOverlap(AActor* OtherActor)
{
	Character = Cast<ABETCharacter>(OtherActor);
}