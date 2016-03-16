// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "EffectOverTime.h"


// Sets default values
AEffectOverTime::AEffectOverTime()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	duration = 5.f;
	InitialLifeSpan = 4.f;
}

// Called when the game starts or when spawned
void AEffectOverTime::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEffectOverTime::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

