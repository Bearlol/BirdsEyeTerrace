// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "AbilityMap.h"
#include "CharacterKim.h"

UAbilityMap::UAbilityMap()
	: Super()
{

	Owner = Cast<ABETCharacter>(this->GetOwner());
	static ConstructorHelpers::FObjectFinder<UBlueprint> MiniMapWidgetAsset(TEXT("/Game/MiniMapWidget"));
	MiniMapWidgetClass = Cast<UClass>(MiniMapWidgetAsset.Object->GeneratedClass);
}

void UAbilityMap::Use()

{
	Super::Use();
	MiniMapWidget = CreateWidget<UMiniMapWidget>(Cast<APlayerController>(Owner->GetController()), MiniMapWidgetClass);
	MiniMapWidget->AddToViewport();
}


void UAbilityMap::DeactivateAbility()
{

}

void UAbilityMap::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{

}


