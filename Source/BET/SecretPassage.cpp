// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "SecretPassage.h"


ASecretPassage::ASecretPassage()
	:Super()
{
	InteractAudio = NULL;
	PrimaryActorTick.bCanEverTick = true;
	TimeToOpen = 2.f;
	OnActorBeginOverlap.AddDynamic(this, &ASecretPassage::OnOverlap);
}


void ASecretPassage::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	FRotator OriginalPosition = FRotator(100.f / TimeToOpen, 0.0f, 0.0f);

	if (!IsOpen)
	{
		if (Secret)
		{
			
			IsOpen = false;

			if (Character != nullptr)
			{
				IsOpen = false;
				TimeToOpen -= DeltaTime;

				if (TimeToOpen <= 0)
				{
					IsOpen = false;
				}
				else
				{
					AddActorWorldRotation((OriginalPosition*DeltaTime));
					UGameplayStatics::PlaySoundAtLocation(this, InteractAudio, GetActorLocation());
					UE_LOG(LogTemp, Display, TEXT("opening%f"), OriginalPosition.Roll);

					if (OriginalPosition.Roll >= 128.f)
					{
						IsInteracted = false;
						IsOpen = true;

					}
				}
			}
		}
	}
}
void ASecretPassage::OnSecret()
{
	Secret = true;
}

bool ASecretPassage::GetSecret()
{
	return Secret;
}

