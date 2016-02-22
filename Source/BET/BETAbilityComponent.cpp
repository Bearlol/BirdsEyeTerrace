// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "BETAbilityComponent.h"


// Sets default values for this component's properties
UBETAbilityComponent::UBETAbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBETAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBETAbilityComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	// ...

	TimeToNextUse -= DeltaTime;
	if (bIsActive)
	{
		Use();
	}
}

void UBETAbilityComponent::Use()
{

}

bool UBETAbilityComponent::ServerActivateAbility_Validate()
{
	return true;
}

void UBETAbilityComponent::ServerActivateAbility_Implementation()
{

}