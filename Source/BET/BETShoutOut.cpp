// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "BETShoutOut.h"


UBETShoutOut::UBETShoutOut()
{
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UBETShoutOut::Use()
{

	UGameplayStatics::PlaySoundAtLocation(this, ShoutAudio, character->GetActorLocation());

}