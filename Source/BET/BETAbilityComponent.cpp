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
	TimeToNextUse = 0.f;
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
	if (blocked)
	{
		blockedDuration = 10.f;
		blocked = false;
	}
	if (blockedDuration > 0.f)
	{
		blockedDuration -= DeltaTime;
	}
	else {
		TimeToNextUse -= DeltaTime;
		if (bIsActive)
		{
			if (CanUse() == true)
			{
				Use();
			}
		}
	}
}

void UBETAbilityComponent::Use()
{
	
	TimeToNextUse = Cooldown;
}


bool UBETAbilityComponent::ServerActivateAbility_Validate()
{
	return true;
}

void UBETAbilityComponent::ServerActivateAbility_Implementation()
{
	ActivateAbility();
}

void UBETAbilityComponent::SetTime()
{
	blocked = true;
}


void UBETAbilityComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UBETAbilityComponent, TimeToNextUse);
}