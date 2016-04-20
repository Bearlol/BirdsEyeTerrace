// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "PickUp.h"


// Sets default values
APickUp::APickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));

	RootComponent = Collider;

	OnActorBeginOverlap.AddDynamic(this, &APickUp::OnOverlap);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachTo(RootComponent);
	bReplicates = true;
}

void APickUp::OnOverlap(AActor* OtherActor)

{
	//ABETCharacter* Character = Cast<ABETCharacter>(OtherActor);
	//if (Character)
	//{

	//}
}



// Called when the game starts or when spawned
void APickUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickUp::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

