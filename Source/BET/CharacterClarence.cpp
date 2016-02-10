// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "CharacterClarence.h"




ACharacterClarence::ACharacterClarence()
	:Super()

{

	ActiveAbility = CreateDefaultSubobject<UClarenceInvisibleAbility>(TEXT("ActiveAbility"));
}


