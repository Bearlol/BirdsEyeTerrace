// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "BETBattery.h"





ABETBattery::ABETBattery()
{
	InteractAudio = NULL;
	Character = nullptr;
	OnActorBeginOverlap.AddDynamic(this, &ABETBattery::OnOverlap);
}


void ABETBattery::Interact()
{
	if (Character != nullptr)
	{
		Character->SetBattery();
		UGameplayStatics::PlaySoundAtLocation(this, InteractAudio, GetActorLocation());
		UE_LOG(LogTemp, Display, TEXT("Battery Restored"));
		this->Destroy();
	}
}
void ABETBattery::OnOverlap(AActor* OtherActor)
{
	Character = Cast<ABETCharacter>(OtherActor);
}


