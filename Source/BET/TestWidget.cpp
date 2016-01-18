// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "GameFramework/PlayerState.h"
#include "TestWidget.h"

FText UTestWidget::GetPlayerName() const
{
	return FText::FromString(GetOwningPlayer()->PlayerState->PlayerName);
}


