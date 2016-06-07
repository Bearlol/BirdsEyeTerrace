// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "BET.h"
#include "BETCharacter.h"
#include "BETInteractable.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/InputSettings.h"


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
	lightIntensity = 15000.f;
	flashLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("Flashlight"));
	flashLight->SetIntensity(lightIntensity);
	flashLight->SetAttenuationRadius(2000.0f);
	flashLight->bVisible = true;
	flashLight->AttachParent = FirstPersonCameraComponent;
	walkSpeed = 300;
	runSpeed = 600;
	MAXSTAMINA = 10;
	widgetChecker = 0;
	stamina = MAXSTAMINA;
	running = false;
	power = true;
	Key = false;
	canLeave = false;
}


void ABETCharacter::BeginPlay()
{
	Super::BeginPlay();
}
//////////////////////////////////////////////////////////////////////////
// Input

void ABETCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// set up gameplay key bindings
	check(InputComponent);
	
//	InputComponent->BindAction("Fire", IE_Pressed, this, &ABETCharacter::OnFire);
	
	InputComponent->BindAction("Interact", IE_Pressed, this, &ABETCharacter::OnInteract);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &ABETCharacter::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &ABETCharacter::LookUpAtRate);
	InputComponent->BindAxis("MoveForward", this, &ABETCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ABETCharacter::MoveRight);
	InputComponent->BindAction("UseActiveAbility", IE_Pressed, ActiveAbility, &UBETAbilityComponent::ActivateAbility);
	InputComponent->BindAction("SetRun", IE_Pressed, this, &ABETCharacter::SetRun);
	InputComponent->BindAction("SetRun", IE_Released, this, &ABETCharacter::EndRun);
	InputComponent->BindAction("SetLight", IE_Pressed, this, &ABETCharacter::SetLight);
	//InputComponent->BindAction("UseActiveAbility", IE_Released, ActiveAbility, &UBETAbilityComponent::DeactivateAbility);
}

void ABETCharacter::SetBattery() {
	lightIntensity = 15000;
	flashLight->SetIntensity(lightIntensity);
	if (BatteryPickUpAudio != nullptr)
	UGameplayStatics::PlaySoundAtLocation(this, BatteryPickUpAudio, GetActorLocation());
	widgetChecker = 1;
}

void ABETCharacter::SetLight()
{
	flashLight->ToggleVisibility();
	power = !power;
	if(FlashlightAudio != nullptr)
	UGameplayStatics::PlaySoundAtLocation(this, FlashlightAudio, GetActorLocation());
}
void ABETCharacter::SetRun()
{
	if (stamina > 3)
	{
		running = true;
		this->GetCharacterMovement()->MaxWalkSpeed = runSpeed;		
	}

}

void ABETCharacter::SetWin() 
{
	canLeave = true;
}

bool ABETCharacter::GetCanLeave()
{
	return canLeave;
}
void ABETCharacter::EndRun()
{
	this->GetCharacterMovement()->MaxWalkSpeed = walkSpeed;
	running = false;
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
			//if (ABETInteractable->InteractAudio != NULL)
			//{
				//UGameplayStatics::PlaySoundAtLocation(this, ABETInteractable->InteractableAudio, GetActorLocation());

				if (ABETInteractable* Interactable = Cast<ABETInteractable>(Result.Actor.Get()))
				{
					UE_LOG(LogTemp, Display, TEXT("INTERACTABLE FOUND"));
					Interactable->Interact();
					//Interactable->OnServerInteract();
				}
			//}
		}
	}

}
/*
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
*/
	



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
			if (running == false) {
				if(WalkAudio != nullptr)
				UGameplayStatics::PlaySoundAtLocation(this, WalkAudio, GetActorLocation());
			}
			if (running == true) {
				if(RunAudio != nullptr)
				UGameplayStatics::PlaySoundAtLocation(this, RunAudio, GetActorLocation());
			}
		}
	
}

void ABETCharacter::MoveRight(float Value)
{
	
		if (Value != 0.0f)
		{
			// add movement in that direction
			AddMovementInput(GetActorRightVector(), Value);
			if (running == false) {
				if (WalkAudio != nullptr)
					UGameplayStatics::PlaySoundAtLocation(this, WalkAudio, GetActorLocation());
			}
			if (running == true) {
				if (RunAudio != nullptr)
					UGameplayStatics::PlaySoundAtLocation(this, RunAudio, GetActorLocation());
			}
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
/*
void ABETCharacter::PickUpWeapon(class AWeaponPickUp * PickedUpWeapon)
{	
		if (PickedUpWeapon->GetWeaponClass())
		{

			ABETWeapon*Weapon = GetWorld()->SpawnActor<ABETWeapon>(PickedUpWeapon->GetWeaponClass(), FVector::ZeroVector, FRotator::ZeroRotator);
			Weapon->AttachRootComponentTo(GetMesh(), TEXT("BN_R_Weapon01"), EAttachLocation::SnapToTarget);
			//BN_R_Weapon01 will change depending on the name of the hand bone.
			if (CurrentWeapon) {
				CurrentWeapon->Destroy();
			}
			CurrentWeapon = Weapon;
			//	PickedUpWeapon = NULL;
		}			
}
*/



void ABETCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (running)
	{
		stamina -= DeltaTime;
		if (stamina <= 0)
		{
			EndRun();
			if(NoStaminaAudio != nullptr)
			UGameplayStatics::PlaySoundAtLocation(this, NoStaminaAudio, GetActorLocation());
		}
	}
	else
	{
		if (stamina < MAXSTAMINA) {
			stamina += DeltaTime / 2;
		}
		else {
			stamina = MAXSTAMINA;
		}
	}
	if (power)
	{
		if (lightIntensity <= 0)
		{		power = !power;
		flashLight->ToggleVisibility();
		lightIntensity = 20;
		}
		else {
			lightIntensity -= DeltaTime * 200;
			flashLight->SetIntensity(lightIntensity);
			if (lightIntensity >= 12000.f)
			{
				if (widgetChecker == 1)
				{
					WidgetBattery->RemoveFromViewport();
					WidgetBattery = NULL;
				}
				if (WidgetBattery == NULL) {
					WidgetBattery = CreateWidget<UUserWidget>(Cast<APlayerController>(this->GetController()), UIBatteryWidgetFull);
					WidgetBattery->AddToViewport();
					widgetChecker = 2;
				}
			}
			else if (lightIntensity < 12000.f && lightIntensity >= 9000.f)
			{
				if (widgetChecker == 2)
				{
					WidgetBattery->RemoveFromViewport();
					WidgetBattery = NULL;
				}
				if (WidgetBattery == NULL) {
					WidgetBattery = CreateWidget<UUserWidget>(Cast<APlayerController>(this->GetController()), UIBatteryWidget80);
					WidgetBattery->AddToViewport();
					widgetChecker = 3;
				}
			}
			else if (lightIntensity < 9000.f && lightIntensity >= 6000.f)
			{
				if (widgetChecker == 3)
				{
					WidgetBattery->RemoveFromViewport();
					WidgetBattery = NULL;
				}
				if (WidgetBattery == NULL) {
					WidgetBattery = CreateWidget<UUserWidget>(Cast<APlayerController>(this->GetController()), UIBatteryWidget60);
					WidgetBattery->AddToViewport();
					widgetChecker = 4;
				}
			}
			else if (lightIntensity < 6000.f && lightIntensity >= 3000.f)
			{
				if (widgetChecker == 4)
				{
					WidgetBattery->RemoveFromViewport();
					WidgetBattery = NULL;
				}
				if (WidgetBattery == NULL) {
					WidgetBattery = CreateWidget<UUserWidget>(Cast<APlayerController>(this->GetController()), UIBatteryWidget40);
					WidgetBattery->AddToViewport();
					widgetChecker = 5;
				}
			}
			else if (lightIntensity < 3000.f && lightIntensity > 0.f)
			{
				if (widgetChecker == 5)
				{
					WidgetBattery->RemoveFromViewport();
					WidgetBattery = NULL;
				}
				if (WidgetBattery == NULL) {
					WidgetBattery = CreateWidget<UUserWidget>(Cast<APlayerController>(this->GetController()), UIBatteryWidget20);
					WidgetBattery->AddToViewport();
					widgetChecker = 6;
				}
			}
			else if (lightIntensity <= 0.f)
			{
				if (widgetChecker == 6)
				{
					WidgetBattery->RemoveFromViewport();
					WidgetBattery = NULL;
				}
				if (WidgetBattery == NULL) {
					WidgetBattery = CreateWidget<UUserWidget>(Cast<APlayerController>(this->GetController()), UIBatteryWidgetEmpty);
					WidgetBattery->AddToViewport();
					widgetChecker = 7;
				}
			}
		}
	}
}

/*
float ABETCharacter::TakeDamage(float TakeDamage, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{


	if (Role == ROLE_Authority)
	{
		float actualDamage = Super::TakeDamage(TakeDamage, DamageEvent, EventInstigator, DamageCauser);
		Health -= actualDamage;
	}

	return 0.f;


	//uncomment for death!!!!
	if (Health <= 0)
	{
		Destroy();
	}
}
*/

void ABETCharacter::OnKey()
{
	Key = true;
}

bool ABETCharacter::GetKey()
{
	return Key;
}