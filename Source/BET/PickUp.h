// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Actor.h"
#include "PickUp.generated.h"

UCLASS()
class BET_API APickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUp();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
protected:
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* Collider;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

protected:
	UFUNCTION()
	virtual void OnOverlap(AActor* OtherActor);

};
