// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BETInteractable.h"
#include "BETCharacter.h"
#include "Engine.h"
#include "SlateCore.h"
#include "Blueprint/UserWidget.h"
#include "BETBattery.generated.h"

/**
 * 
 */
UCLASS()
class BET_API ABETBattery : public ABETInteractable
{
	GENERATED_BODY()
		ABETBattery();
public:

		virtual void Interact() override;
		
		float duration;
		bool WidgetActive;


protected:
	UFUNCTION()
	virtual void OnOverlap(AActor* OtherActor) override;
	ABETCharacter* Character;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = UI)
		TSubclassOf<UUserWidget> UIWidget;

	UPROPERTY()
		UUserWidget* WidgetInstance;

	virtual void Tick(float DeltaTime) override;
	
};
