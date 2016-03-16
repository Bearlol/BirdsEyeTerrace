// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "AreaOfEffect.h"
#include "BETCharacter.h"
#include "Engine.h"



UAreaOfEffect::UAreaOfEffect()
:Super()
{

}

void UAreaOfEffect::Use()
{
	static FName NAME_TestMove = FName(TEXT("TestMove"));
	FCollisionQueryParams SphereParams(NAME_TestMove, false, GetOwner());
	FCollisionObjectQueryParams QueryParams = FCollisionObjectQueryParams(FCollisionObjectQueryParams::InitType::AllDynamicObjects);
	TArray<FOverlapResult> Overlaps;

	GetWorld()->OverlapMultiByObjectType(Overlaps, GetOwner()->GetActorLocation(), FQuat::Identity, QueryParams, FCollisionShape::MakeSphere(500.f), SphereParams);

	for (int32 i = 0; i < Overlaps.Num(); ++i)
	{ 
		//
		
		FOverlapResult const& Overlap = Overlaps[i];
		ABETCharacter* Mine = Cast<ABETCharacter>(Overlap.GetActor());
		
		
		if (Mine != nullptr)
		{
			DrawDebugSphere(GetWorld(), GetOwner()->GetActorLocation(), 24, 32, FColor(255, 0, 0), false, -1.f);
		}
	}
}