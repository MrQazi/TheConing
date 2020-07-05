// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CH_Fighter.h"
#include "CH_Player.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UAIPerceptionStimuliSourceComponent;

/**
 * 
 */
UCLASS()
class THECONING_API ACH_Player : public ACH_Fighter
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FTransform t;
	/*
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* playerCamera = nullptr;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, SimpleDisplay, meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* cameraArm = nullptr;
	*/

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		UAIPerceptionStimuliSourceComponent* stimuli = nullptr;

public:
	ACH_Player();
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	void MoveFB(float value);
	void MoveLR(float value);
};
