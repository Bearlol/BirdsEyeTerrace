// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "TeleportingPaintings.h"

ATeleportingPaintings::ATeleportingPaintings()
{
	Character = nullptr;
	//OnActorBeginOverlap.AddDynamic(this, &ATeleportingPaintings::OnOverlap);
	OnActorBeginOverlap.AddDynamic(this, &ATeleportingPaintings::OnOverlap);
}

void ATeleportingPaintings::Interact()
{
	Super::Interact();
	
	// if targetlocation is set 
	if (TargetLocation != nullptr)
	{
		//teleport player
		//find character that interacts with it then if it is spooky then setlocation
		FVector ActorLocation = TargetLocation->GetActorLocation();
		//ActorLocation.Z += 10.0f;
		//ActorLocation.X -= 10.0f;
		ActorLocation.Y += 30.0f;

		// if character is found in range
		if (Character != nullptr) {
			Character->SetActorLocation(ActorLocation, false);
		}
	}
}

void ATeleportingPaintings::OnOverlap(AActor* OtherActor)
{
	Character = Cast<ABETCharacter>(OtherActor);
}