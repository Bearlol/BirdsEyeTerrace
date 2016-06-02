// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "SecretSwitch.h"


ASecretSwitch::ASecretSwitch()
	:Super()
{
	InteractAudio = NULL;
	GetSecret = nullptr;
	PrimaryActorTick.bCanEverTick = true;
	OnActorBeginOverlap.AddDynamic(this, &ASecretSwitch::OnOverlap);
}

void ASecretSwitch::OnOverlap(AActor* OtherActor)
{
	Character = Cast<ABETCharacter>(OtherActor);

}


void ASecretSwitch::Interact()
{
	IsInteracted = true;
	GetSecret->GetSecret();
	
}

