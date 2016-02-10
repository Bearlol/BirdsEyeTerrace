// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateCore.h"
#include "BETCharacter.h"
#include "Blueprint/UserWidget.h"
#include "TestWidget.generated.h"

/**
 * 
 */
UCLASS()
class BET_API UTestWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintCallable, Category = Information)
		FText GetPlayerName() const;
	UFUNCTION(BlueprintCallable, Category = Information)
		float Health() const;
	UFUNCTION(BlueprintCallable, Category = Information)
		float Shield() const;
	
	
};
