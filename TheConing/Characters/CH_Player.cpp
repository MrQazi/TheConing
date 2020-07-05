// Fill out your copyright notice in the Description page of Project Settings.


#include "CH_Player.h"
#include "GameFramework/Character.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
//#include "Camera/CameraComponent.h"
//#include "GameFramework/SpringArmComponent.h"

ACH_Player::ACH_Player() {

	SetGenericTeamId(FGenericTeamId(ETeamAttitude::Friendly));

	wPunch_L = CreateDefaultSubobject<USphereComponent>(TEXT("L_Punch"));
	wPunch_R = CreateDefaultSubobject<USphereComponent>(TEXT("R_Punch"));

	wPrimary = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("wPrimary"));
	wSecondary = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("wSecondary"));
	/*
	cameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	cameraArm->SetupAttachment(RootComponent);

	playerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	playerCamera->SetupAttachment(cameraArm);
	*/
}


void ACH_Player::BeginPlay()
{
	Super::BeginPlay();
}


void ACH_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent){
	PlayerInputComponent->BindAxis("MoveFB",this,&ACH_Player::MoveFB);
	PlayerInputComponent->BindAxis("MoveLR",this,&ACH_Player::MoveLR);
}
void ACH_Player::MoveFB(float value){
	AddMovementInput(GetActorForwardVector(),value,false);
}
void ACH_Player::MoveLR(float value){
	AddMovementInput(GetActorRightVector(),value,false);
}