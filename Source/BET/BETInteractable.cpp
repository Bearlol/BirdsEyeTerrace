// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "BETInteractable.h"


// Sets default values
ABETInteractable::ABETInteractable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	Collider->SetBoxExtent(FVector(1.f, 1.f, 1.f));
	Collider->BodyInstance.SetCollisionProfileName("InteractableTrigger");

	RootComponent = Collider;


}

void ABETInteractable::Interact()
{
	//GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Yellow, TEXT("INTERACT"));
	UE_LOG(LogTemp, Display, TEXT("INTERACT"));
}


