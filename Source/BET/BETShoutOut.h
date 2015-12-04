// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BETAbilityComponent.h"
#include "BETShoutOut.generated.h"

/**
 * 
 */
UCLASS()
class BET_API UBETShoutOut : public UBETAbilityComponent
{
	GENERATED_BODY()
		
public:
	UBETShoutOut();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class USoundBase* ShoutAudio;
	
protected:
	virtual void Use() override;
	UPROPERTY(EditDefaultsOnly)
	class AActor *character;
};
