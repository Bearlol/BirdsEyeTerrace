// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "BET.h"
#include "BETCharacter.h"
#include "BETProjectile.h"
#include "WeaponPickUp.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/InputSettings.h"
#include "BETProjectileWeapon.h"
#include "BETWeapon.h"

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// ABETCharacter

ABETCharacter::ABETCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	Health = 0.5f;
	Shield = 0.5f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->AttachParent = GetCapsuleComponent();
	FirstPersonCameraComponent->RelativeLocation = FVector(0, 0, 64.f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->AttachParent = FirstPersonCameraComponent;
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;


	// Note: The ProjectileClass and the skeletal mesh/anim blueprints for Mesh1P are set in the
	// derived blueprint asset named MyCharacter (to avoid direct content references in C++)
	CurrentWeapon = NULL;
}


void ABETCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (WeaponClass)
	{
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.Instigator = this;
		Weapon = GetWorld()->SpawnActor<ABETWeapon>(WeaponClass, SpawnParameters);
		Weapon->AttachRootComponentToActor(this);
	}
}
//////////////////////////////////////////////////////////////////////////
// Input

void ABETCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// set up gameplay key bindings
	check(InputComponent);
	
	InputComponent->BindAction("Fire", IE_Pressed, this, &ABETCharacter::OnFire);
	
	InputComponent->BindAction("Interact", IE_Pressed, this, &ABETCharacter::OnInteract);
	InputComponent->BindAxis("MoveForward", this, &ABETCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ABETCharacter::MoveRight);
	
	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &ABETCharacter::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &ABETCharacter::LookUpAtRate);

	InputComponent->BindAction("UseActiveAbility", IE_Pressed, ActiveAbility, &UBETAbilityComponent::ActivateAbility);
	InputComponent->BindAction("UseActiveAbility", IE_Released, ActiveAbility, &UBETAbilityComponent::DeactivateAbility);
}

void ABETCharacter::OnInteract()
{
	FCollisionQueryParams TraceParams(FName(TEXT("Interact Trace")), true);
	TraceParams.bTraceComplex = true;
	TraceParams.bReturnPhysicalMaterial = false;

	TraceParams.AddIgnoredActor(this);

	// Re-init hit info

	TArray<FOverlapResult>Overlaps;

	if (GetWorld()->OverlapMultiByChannel(Overlaps,
		GetActorLocation(),
		FQuat(),
		ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(50.f),
		TraceParams))
	{
		for (FOverlapResult Result : Overlaps)
		{
			if (ABETInteractable* Interactable = Cast<ABETInteractable>(Result.Actor.Get()))
			{
				UE_LOG(LogTemp, Display, TEXT("INTERACTABLE FOUND"));
				Interactable->Interact();
			}
		}
		
	}

}

void ABETCharacter::OnFire()
{ 
	if (Weapon){
		Weapon->Fire();
		//}

		// try and play the sound if specified
		if (Weapon->FireSound != NULL)
		{
			UGameplayStatics::PlaySoundAtLocation(this, Weapon->FireSound, GetActorLocation());
		}

		// try and play a firing animation if specified
		if (Weapon->FireAnimation != NULL)
		{
			// Get the animation object for the arms mesh
			UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
			if (AnimInstance != NULL)
			{
				AnimInstance->Montage_Play(Weapon->FireAnimation, 1.f);
			}
		}
	}
}

	



void ABETCharacter::BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if( TouchItem.bIsPressed == true )
	{
		return;
	}
	TouchItem.bIsPressed = true;
	TouchItem.FingerIndex = FingerIndex;
	TouchItem.Location = Location;
	TouchItem.bMoved = false;
}

void ABETCharacter::EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if (TouchItem.bIsPressed == false)
	{
		return;
	}
	if( ( FingerIndex == TouchItem.FingerIndex ) && (TouchItem.bMoved == false) )
	{
		OnFire();
	}
	TouchItem.bIsPressed = false;
}

void ABETCharacter::TouchUpdate(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if ((TouchItem.bIsPressed == true) && ( TouchItem.FingerIndex==FingerIndex))
	{
		if (TouchItem.bIsPressed)
		{
			if (GetWorld() != nullptr)
			{
				UGameViewportClient* ViewportClient = GetWorld()->GetGameViewport();
				if (ViewportClient != nullptr)
				{
					FVector MoveDelta = Location - TouchItem.Location;
					FVector2D ScreenSize;
					ViewportClient->GetViewportSize(ScreenSize);
					FVector2D ScaledDelta = FVector2D( MoveDelta.X, MoveDelta.Y) / ScreenSize;									
					if (ScaledDelta.X != 0.0f)
					{
						TouchItem.bMoved = true;
						float Value = ScaledDelta.X * BaseTurnRate;
						AddControllerYawInput(Value);
					}
					if (ScaledDelta.Y != 0.0f)
					{
						TouchItem.bMoved = true;
						float Value = ScaledDelta.Y* BaseTurnRate;
						AddControllerPitchInput(Value);
					}
					TouchItem.Location = Location;
				}
				TouchItem.Location = Location;
			}
		}
	}
}

void ABETCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void ABETCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void ABETCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ABETCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

bool ABETCharacter::EnableTouchscreenMovement(class UInputComponent* InputComponent)
{
	bool bResult = false;
	if(FPlatformMisc::GetUseVirtualJoysticks() || GetDefault<UInputSettings>()->bUseMouseForTouch )
	{
		bResult = true;
		InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &ABETCharacter::BeginTouch);
		InputComponent->BindTouch(EInputEvent::IE_Released, this, &ABETCharacter::EndTouch);
		InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &ABETCharacter::TouchUpdate);
	}
	return bResult;
}

void ABETCharacter::HealthPickup()
{
	Health = Health + 0.25f;
}

void ABETCharacter::ShieldPickup()
{
	Shield = Shield + 0.25f;
}

void ABETCharacter::PickUpWeapon(class AWeaponPickUp * PickedUpWeapon)
{
	if (PickedUpWeapon->GetWeaponClass())
	{

		ABETWeapon*Weapon = GetWorld()->SpawnActor<ABETWeapon>(PickedUpWeapon->GetWeaponClass(), FVector::ZeroVector, FRotator::ZeroRotator);
		Weapon->AttachRootComponentToActor(this, TEXT("hand_r"));
		//HandR will change depending on the name of the hand bone.
		CurrentWeapon = Weapon;
	}
}