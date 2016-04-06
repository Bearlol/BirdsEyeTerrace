// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "AbilityBlockAbilities.h"
#include "CharacterSam.h"




ACharacterSam::ACharacterSam()
	:Super()

{
	ActiveAbility = CreateDefaultSubobject<UAbilityBlockAbilities>(TEXT("ActiveAbility"));
}
