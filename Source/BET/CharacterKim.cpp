// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "CharacterKim.h"


ACharacterKim::ACharacterKim()
	:Super()
{

	ActiveAbility = CreateDefaultSubobject<UAbilityMap>(TEXT("ActiveAbility"));

//	static ConstructorHelpers::FObjectFinder<UBlueprint> MiniMapWidgetAsset(TEXT("/Game/MiniMapWidget"));
//	MiniMapWidgetClass = Cast<UClass>(MiniMapWidgetAsset.Object->GeneratedClass);
}

void ACharacterKim::OnRep_Controller()
{
	Super::OnRep_Controller();

	//MiniMapWidget = CreateWidget<UMiniMapWidget>(Cast<APlayerController>(GetController()), MiniMapWidgetClass);
	//MiniMapWidget->AddToViewport();
}


void ACharacterKim::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value* runSpeed);
		if (ActiveAbility->bIsActive == true) {
			ActiveAbility->DeactivateAbility();
		}
	}
}

void ACharacterKim::MoveRight(float Value)
{
//	if (Stunned->isActive == false) {
		if (Value != 0.0f)
		{
			// add movement in that direction
			AddMovementInput(GetActorRightVector(), Value* runSpeed);
			if (ActiveAbility->bIsActive == true) {
				ActiveAbility->DeactivateAbility();
			}
		}
//	}
}