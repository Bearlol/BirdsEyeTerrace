// Fill out your copyright notice in the Description page of Project Settings.

#include "BET.h"
#include "BETLightSwitch.h"


ABETLightSwitch :: ABETLightSwitch()
{
	DesiredIntensity = 30000.f;
	PointLight1 = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight1"));
	PointLight1->Intensity = DesiredIntensity;
	PointLight1->bVisible = true;
	RootComponent = PointLight1;


}

void ABETLightSwitch::Interact(){
	
		PointLight1->ToggleVisibility();
		
}
