// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "BET.h"
#include "BETHUD.h"
#include "Engine/Canvas.h"
#include "TextureResource.h"
#include "CanvasItem.h"

ABETHUD::ABETHUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshiarTexObj(TEXT("/Game/FirstPerson/Textures/FirstPersonCrosshair"));
	CrosshairTex = CrosshiarTexObj.Object;

	//static ConstructorHelpers::FObjectFinder<UTexture2D> HealthBarTexPath(TEXT("/Game/FirstPerson/Textures/health"));
	//healthBarTexture = HealthBarTexPath.Object;

//	static ConstructorHelpers::FObjectFinder<UBlueprint> MiniMapWidgetAsset(TEXT("/Game/MiniMapWidget"));
//	MiniMapWidgetClass = Cast<UClass>(MiniMapWidgetAsset.Object->GeneratedClass);
}

int32 health = 200;

void ABETHUD::BeginPlay()
{
	Super::BeginPlay();

//	MiniMapWidget = CreateWidget<UMiniMapWidget>(GetOwningPlayerController(), MiniMapWidgetClass);
//	MiniMapWidget->AddToViewport();
}

void ABETHUD::DrawHUD()
{
	Super::DrawHUD();

	drawMiniMap();
	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition( (Center.X - (CrosshairTex->GetSurfaceWidth() * 0.5)),
										   (Center.Y - (CrosshairTex->GetSurfaceHeight() * 0.5f)) );

	// draw the crosshair
	FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem( TileItem );
}


//minimap for kim
void ABETHUD::drawMiniMap()
{
	FCanvasIcon MiniMapIcon = UCanvas::MakeIcon(miniMapTexture, 0, 0, health, 20);
	Canvas->DrawIcon(MiniMapIcon, (Canvas->SizeX) / 2.5, 20, 0.0f);
}
