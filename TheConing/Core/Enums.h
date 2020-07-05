#pragma once
#include "CoreMinimal.h"

UENUM(BlueprintType)
enum EItemType
{
	Coins UMETA(DisplayName = "COINS"),
	Edible UMETA(DisplayName = "EDIBLE"),
	Weapon UMETA(DisplayName = "WEAPON"),
	Material UMETA(DisplayName = "MATERIAL")
};
UENUM(BlueprintType)
enum EEdibleType
{
	Health UMETA(DisplayName = "HEALTH")
};

UENUM(BlueprintType)
enum EWeaponType
{
	UnArmed UMETA(DisplayName = "UNARMED"),
	Primary UMETA(DisplayName = "PRIMARY"),
	Secondary UMETA(DisplayName = "SECONDARY")
};

UENUM(BlueprintType)
enum EGameMaterialType {
	Wood UMETA(DisplayName = "WOOD")
};