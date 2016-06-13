// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BETInteractable.h"
#include "BETCharacter.h"
#include "SlateCore.h"
#include "Engine.h"
#include "Blueprint/UserWidget.h"
#include "BETVictoryCondition.generated.h"

/**
 * 
 */
UCLASS()
class BET_API ABETVictoryCondition : public ABETInteractable
{
	GENERATED_BODY()

		ABETVictoryCondition();

protected:
	virtual void Interact() override;
	UFUNCTION()
		virtual void OnOverlap(AActor* OtherActor);
	ABETCharacter* Character;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = UI)
		TSubclassOf<UUserWidget> UIFithStep;


	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
		UUserWidget* WinCondition;
public:
	
	float duration;
	bool WidgetActive;

	
};
