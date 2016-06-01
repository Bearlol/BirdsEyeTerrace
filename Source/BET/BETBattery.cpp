// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "BETBattery.h"





ABETBattery::ABETBattery()
{
	InteractAudio = NULL;
	Character = nullptr;
	OnActorBeginOverlap.AddDynamic(this, &ABETBattery::OnOverlap);
	PrimaryActorTick.bCanEverTick = true;
	WidgetActive = false;
}


void ABETBattery::Interact()
{
	if (Character != nullptr)
	{
		if (WidgetActive == false) 
		{
			Character->SetBattery();
			UGameplayStatics::PlaySoundAtLocation(this, InteractAudio, GetActorLocation());
			this->SetActorHiddenInGame(true);
			this->SetActorEnableCollision(false);
			UE_LOG(LogTemp, Display, TEXT("Battery Restored"));
			WidgetInstance = CreateWidget<UUserWidget>(Cast<APlayerController>(Character->GetController()), UIWidget);
			WidgetInstance->AddToViewport();
			duration = 2.0f;
			WidgetActive = true;
		}
	}
}
void ABETBattery::OnOverlap(AActor* OtherActor)
{
	Character = Cast<ABETCharacter>(OtherActor);
}

void ABETBattery::Tick(float DeltaTime)
{
	if (WidgetActive)
	{
		duration -= DeltaTime;
		if (duration <= 0.f)
		{
			WidgetInstance->RemoveFromViewport();
			WidgetInstance->Destruct();
			this->K2_DestroyActor();
		}
	}
}


