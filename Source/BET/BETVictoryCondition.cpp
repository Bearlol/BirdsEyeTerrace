// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "BETVictoryCondition.h"


ABETVictoryCondition::ABETVictoryCondition()
{
	Character = nullptr;
	OnActorBeginOverlap.AddDynamic(this, &ABETVictoryCondition::OnOverlap);
	WidgetActive = false;
	PrimaryActorTick.bCanEverTick = true;
}

void ABETVictoryCondition::Interact()
{
	if (WidgetActive == false)
	{
		if (Character != nullptr) {
			Character->SetWin();
			UGameplayStatics::PlaySoundAtLocation(this, InteractAudio, GetActorLocation());
			this->SetActorHiddenInGame(true);
			this->SetActorEnableCollision(false);
			WinCondition = CreateWidget<UUserWidget>(Cast<APlayerController>(Character->GetController()), UIFithStep);
			WinCondition->AddToViewport();
			duration = 10.0f;
			WidgetActive = true;
		}
	}
}


void ABETVictoryCondition::OnOverlap(AActor* OtherActor)
{
	Character = Cast<ABETCharacter>(OtherActor);
}

void ABETVictoryCondition::Tick(float DeltaTime)
{
	if (WidgetActive)
	{
		duration -= DeltaTime;
		if (duration <= 0.f)
		{
			WinCondition->RemoveFromViewport();
			WinCondition->Destruct();
			this->K2_DestroyActor();
		}
	}
}