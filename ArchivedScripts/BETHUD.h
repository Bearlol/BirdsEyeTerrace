// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "MiniMapWidget.h"
#include "BETHUD.generated.h"

UCLASS()
class ABETHUD : public AHUD
{
	GENERATED_BODY()

public:
	ABETHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;
	virtual void BeginPlay() override;
	void drawMiniMap();

	UTexture2D* miniMapTexture;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

//	TSubclassOf<UMiniMapWidget> MiniMapWidgetClass;
//	UMiniMapWidget* MiniMapWidget;

	

};

