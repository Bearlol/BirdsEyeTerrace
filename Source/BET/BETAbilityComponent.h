// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UnrealNetwork.h"
#include "Components/ActorComponent.h"
#include "BETAbilityComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BET_API UBETAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBETAbilityComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	virtual bool CanUse() { return TimeToNextUse <= 0.f; }

	virtual void ActivateAbility()   { 
		bIsActive = true;
	}
	virtual void DeactivateAbility() { bIsActive = false; }
	bool bIsActive;
protected:
	virtual void Use();
	UPROPERTY(EditDefaultsOnly)
		float Cooldown;

private:
	float TimeToNextUse;
	
	UFUNCTION(Server, Reliable, WithValidation)
		virtual void ServerActivateAbility();
	
};
