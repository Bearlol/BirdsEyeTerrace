// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "BETEscape.h"

ABETEscape::ABETEscape()
{
	Character = nullptr;
	OnActorBeginOverlap.AddDynamic(this, &ABETEscape::OnOverlap);
}

void ABETEscape::Interact()
{
	if (Character != nullptr) 
	{
		if (Character->GetCanLeave())
		{
			FName LevelName = "/Game/FirstPersonCPP/Maps/MainMenu";
			UGameplayStatics::OpenLevel(GWorld, LevelName, false);
		}
	}
}


void ABETEscape::OnOverlap(AActor* OtherActor)
{
	Character = Cast<ABETCharacter>(OtherActor);
}


