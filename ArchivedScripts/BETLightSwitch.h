// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BETInteractable.h"
#include "BETLightSwitch.generated.h"

/**
 * 
 */
UCLASS()
class BET_API ABETLightSwitch : public ABETInteractable
{
	GENERATED_BODY()
public: 
	/**Point Light Component**/
	UPROPERTY(EditDefaultsOnly, Category = "Switch Components")
	class UPointLightComponent* PointLight1;
	/** Sphere Component **/
//	UPROPERTY(EditDefaultsOnly, Category = "Switch Components")
//	class USphereComponent* Sphere1;
	
	ABETLightSwitch();
	virtual void Interact() override;
private:
	UPROPERTY(EditDefaultsOnly, Category = "Switch Variables")
		float DesiredIntensity;

	
};
