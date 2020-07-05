// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PC_Player.generated.h"

/**
 * 
 */
UCLASS()
class THECONING_API APC_Player : public APlayerController
{
	GENERATED_BODY()
private:
	FVector2D Point = {};
	int32_t x, y;

public:
	virtual bool InputTouch(uint32 Handle, ETouchType::Type Type, const FVector2D& TouchLocation, float Force, FDateTime DeviceTimestamp, uint32 TouchpadIndex) override;
	
};
