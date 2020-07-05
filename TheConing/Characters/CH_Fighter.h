// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CH_Human.h"
#include "Core/Structs.h"
#include "Array.h"
#include "Core/Enums.h"
#include "CH_Fighter.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class AwArrow;

/**
 * 
 */
UCLASS()
class THECONING_API ACH_Fighter : public ACH_Human
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		TEnumAsByte<EWeaponType> wType = EWeaponType::UnArmed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	FName wCategory = "EnemyWeapon";
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	TArray<FName> cmbAttack = { "0","1" };
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	uint8 Combo = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		TArray<UAnimMontage*> AttackMontages;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		TArray<FWeapon> Weapons;

	UPROPERTY(Category = Weapon, VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		USphereComponent* wPunch_R = nullptr;
	UPROPERTY(Category = Weapon, VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		USphereComponent* wPunch_L = nullptr;

	UPROPERTY(Category = Weapon, BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* wPrimary = nullptr;
	UPROPERTY(Category = Weapon, BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* wSecondary = nullptr;

	FAttachmentTransformRules rules = { EAttachmentRule::SnapToTarget,EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative,true };

	UPROPERTY(Category = Weapon, VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		AwArrow* arrow = nullptr;
public:
	ACH_Fighter();
	UFUNCTION()
	void Hit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION(BlueprintCallable)
		void SetWeapon(FWeapon Weapon);
	virtual void TakeHit(float damage, AActor* attacker) override;
	UFUNCTION(BlueprintCallable)
	void Attack();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SendAlert();
	virtual void OnConstruction(const FTransform& Transform) override;
};
