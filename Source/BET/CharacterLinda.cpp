// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "AbilitySnare.h"
#include "CharacterLinda.h"




ACharacterLinda::ACharacterLinda()
	:Super()

{
	ActiveAbility = CreateDefaultSubobject<UAbilitySnare>(TEXT("ActiveAbility"));
}
