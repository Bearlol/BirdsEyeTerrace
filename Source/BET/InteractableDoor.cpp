// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "InteractableDoor.h"



AInteractableDoor::AInteractableDoor()
:Super()

{
	TimeToOpen = 3.f;
}



void AInteractableDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsInteracted)
	{
		TimeToOpen -= DeltaTime;
		if (TimeToOpen <= 0)
		{
			IsInteracted = false;
			IsOpen = !IsOpen;
		}
		else
		{
			IsOpen = true;

			
			FRotator MyNewOrientation = FRotator::ZeroRotator;
			SetActorRotation(MyNewOrientation);

			FRotator TimeToOpen = FRotator(0.0f, 0.0f, 90.f);

			AddActorLocalRotation(TimeToOpen*DeltaTime);
			AddActorWorldRotation(TimeToOpen *DeltaTime);

		}
	}
}


void AInteractableDoor::Interact() 
{

	IsInteracted = true;

}