// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "GameFramework/PlayerState.h"
#include "TestWidget.h"

FText UTestWidget::GetPlayerName() const
{
	return FText::FromString(GetOwningPlayer()->PlayerState->PlayerName);
}


float UTestWidget::Health() const
{
	ABETCharacter* Character = Cast<ABETCharacter>(GetOwningPlayerPawn());
	if (Character)
	{
		return (Character->Health);
	}
	return (0);
}

float UTestWidget::Shield() const
{
	ABETCharacter* Character = Cast<ABETCharacter>(GetOwningPlayerPawn());
	if (Character)
	{
		return (Character->Shield);
	}
	return (0);
}