// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "BETKey.h"


ABETKey::ABETKey()
{
	InteractAudio = NULL;
	Character = nullptr;
	OnActorBeginOverlap.AddDynamic(this, &ABETKey::OnOverlap);
}


void ABETKey::Interact()
{
	if (Character != nullptr)
	{
		Character->OnKey();
		UGameplayStatics::PlaySoundAtLocation(this,InteractAudio, GetActorLocation());
		UE_LOG(LogTemp, Display, TEXT("Picked up a key"));
		this->Destroy();
	}
}
void ABETKey::OnOverlap(AActor* OtherActor)
{
	Character = Cast<ABETCharacter>(OtherActor);
}

