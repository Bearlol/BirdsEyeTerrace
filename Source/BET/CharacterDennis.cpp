// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "CharacterDennis.h"



ACharacterDennis::ACharacterDennis()
	:Super()

{
	ActiveAbility = CreateDefaultSubobject<UAbilityBlockAbilities>(TEXT("ActiveAbility"));
}
