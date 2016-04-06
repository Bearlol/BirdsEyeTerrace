// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "AreaOfEffect.h"
#include "Engine.h"




UAreaOfEffect::UAreaOfEffect()
:Super()
{
	//debuff = CreateDefaultSubobject<AEffectOverTime>(TEXT("debuffApplied"));
}

void UAreaOfEffect::Use()
{
	Super::Use();
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

		//	AEffectOverTime* appliedDebuff;
		if (Mine != nullptr)
		{
			//appliedDebuff = debuff;
//			if (debuff){

			UsedFunction(Mine);

			//Mine->Destroy();
			//					appliedDebuff->SetActive();
//					appliedDebuff->AttachRootComponentToActor(Mine);		
//					DrawDebugSphere(GetWorld(), GetOwner()->GetActorLocation(), 24, 32, FColor(255, 0, 0), false, -1.f);
//			}
			//This is where you will attach an effect over time...			
		}
	}
	Overlaps.Empty();
	DeactivateAbility();
}

void UAreaOfEffect::UsedFunction(ABETCharacter* character)
{
}
