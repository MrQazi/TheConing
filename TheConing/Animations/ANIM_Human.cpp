// Fill out your copyright notice in the Description page of Project Settings.


#include "ANIM_Human.h"
#include "GameFramework/Character.h"

void UANIM_Human::NativeBeginPlay()
{
	if (TryGetPawnOwner()) {
		human = (ACharacter*)TryGetPawnOwner();
	}
}

void UANIM_Human::NativeUpdateAnimation(float DeltaSeconds)
{
	if (human) {
		FVector v = human->GetVelocity();
		Forward_Speed = FVector::DotProduct(v, human->GetActorForwardVector());
		Right_Speed = FVector::DotProduct(v, human->GetActorRightVector());
	}
}

