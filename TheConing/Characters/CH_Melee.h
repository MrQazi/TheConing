// Enjoy

#pragma once

#include "CoreMinimal.h"
#include "Characters/CH_Fighter.h"
#include "CH_Melee.generated.h"

/**
 * 
 */
UCLASS()
class THECONING_API ACH_Melee : public ACH_Fighter
{
	GENERATED_BODY()

public:
	ACH_Melee();
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
};
