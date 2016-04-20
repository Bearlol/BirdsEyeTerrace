// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "InteractableDoor.h"



AInteractableDoor::AInteractableDoor()
:Super()

{
	PrimaryActorTick.bCanEverTick = true;
	TimeToOpen = 2.f;

}

void AInteractableDoor::Interact()
{

	IsInteracted = true;

}

void AInteractableDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	FRotator NewPosition = FRotator(0.0f, (100.f / TimeToOpen), 0.0f);
	

	if (IsInteracted && !IsOpen)
	{
		
		TimeToOpen -= DeltaTime;

		if (TimeToOpen <= 0)
		{
			IsInteracted = false;
		}
		else
		{
			AddActorWorldRotation((NewPosition*DeltaTime).GetInverse());

			UE_LOG(LogTemp, Display, TEXT("opening%f"), NewPosition.Yaw);

			if (NewPosition.Yaw >= 128.f)
			{
				IsInteracted = false;
				IsOpen = true;
			}
		}
	}
	else if (IsOpen == true && IsInteracted)
	{
		TimeToOpen -= DeltaTime;

		AddActorWorldRotation(NewPosition*DeltaTime);
		UE_LOG(LogTemp, Display, TEXT("closing%f"), NewPosition.Yaw);
		
		
		if (NewPosition.Yaw >= 330.f)
		{
			IsInteracted = false;
			IsOpen = false;
		}
	}
}

