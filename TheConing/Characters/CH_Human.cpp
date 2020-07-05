// Fill out your copyright notice in the Description page of Project Settings.


#include "CH_Human.h"
#include "Classes/AIController.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimInstance.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"

ACH_Human::ACH_Human() {
	SetGenericTeamId(FGenericTeamId(ETeamAttitude::Neutral));
}

void ACH_Human::OnConstruction(const FTransform& Transform) {
	Super::OnConstruction(Transform);
	if (aiController != nullptr)
		AIControllerClass = aiController;
}

void ACH_Human::TakeHit(float damage,AActor* attacker)
{
	health -= damage;
	if (health <= 0) {
		Die();
	}
	else {
		SetActorRotation(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), attacker->GetActorLocation()),ETeleportType::TeleportPhysics);
		AddMovementInput(GetActorForwardVector(), -1.0f, false);
		GetMesh()->GetAnimInstance()->PlaySlotAnimationAsDynamicMontage(HitAnim, "FullBody");
	}
}

void ACH_Human::Die()
{	
	GetCapsuleComponent()->SetEnableGravity(false);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	PlayAnimMontage(DeathMontage);
}
