// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BETAbilityComponent.h"
#include "BETCharacter.h"
#include "Blueprint/UserWidget.h"
#include "ClarenceInvisibleAbility.generated.h"

/**
 * 
 */
UCLASS()
class BET_API UClarenceInvisibleAbility : public UBETAbilityComponent
{
	GENERATED_BODY()
		UClarenceInvisibleAbility();
protected:
	//void TriggerBody();
	virtual void Use() override;
	ABETCharacter* Owner;
	UPROPERTY(EditDefaultsOnly)
		float duration;
	UPROPERTY(EditDefaultsOnly)
		float maxDuration;
	virtual void DeactivateAbility() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY()
		UUserWidget* AbilityWidget;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = UI)
		TSubclassOf<UUserWidget> ActiveAbilityUI;
};
