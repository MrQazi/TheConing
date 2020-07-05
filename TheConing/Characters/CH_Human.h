// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GenericTeamAgentInterface.h"
#include "CH_Human.generated.h"

class UAnimMontage;
class AAIController;
class UAnimSequenceBase;
class ACH_Fighter;


/**
 * 
 */
UCLASS()
class THECONING_API ACH_Human : public ACharacter, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		float health = 1.f;
	UPROPERTY(EditAnywhere)
		UAnimMontage* DeathMontage = nullptr;
	UPROPERTY(EditAnywhere)
		UAnimSequenceBase* HitAnim = nullptr;
public:
	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn="true"))
		TSubclassOf<AAIController> aiController = nullptr;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	bool Ready = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		UAnimMontage* TalkMontage = nullptr;
public:
	ACH_Human();
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void TakeHit(float damage, AActor* attacker);
	UFUNCTION(BlueprintCallable)
	void Die();
};
