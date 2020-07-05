// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "PC_Player.h"
#include "Kismet/KismetMathLibrary.h"

bool APC_Player::InputTouch(uint32 Handle, ETouchType::Type Type, const FVector2D& TouchLocation, float Force, FDateTime DeviceTimestamp, uint32 TouchpadIndex)
{
    GetViewportSize(x, y);
	switch (Type)
	{
    case ETouchType::Began:
        Point = (
                UKismetMathLibrary::InRange_FloatFloat(TouchLocation.X, x / 2, x - (x / 8), true, true)
                &&
                UKismetMathLibrary::InRange_FloatFloat(TouchLocation.Y, y / 4, y - (y / 6), true, true)
                ) ?
            TouchLocation : FVector2D();
        break;
	case ETouchType::Moved:
        if (!UKismetMathLibrary::EqualEqual_Vector2DVector2D(Point, FVector2D())) {
            AddYawInput((TouchLocation - Point).X / 5);
            float v = (TouchLocation - Point).Y / 5;
			float p = GetControlRotation().Pitch;
            if (!((p < 180 && p>40 && v < 0) && (p > 180 && p < 340 && v > 0)))
                AddPitchInput(v);
            Point = TouchLocation;
        }
        break;
	case ETouchType::Ended:
        Point = FVector2D();
        break;
    default:
        break;
	}
    return Super::InputTouch(Handle, Type, TouchLocation, Force, DeviceTimestamp, TouchpadIndex);
}
