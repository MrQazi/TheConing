// Fill out your copyright notice in the Description page of Project Settings.


#include "CH_Fighter.h"
#include "GameFramework/Character.h"
#include "Core/Enums.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Engine/Engine.h"

ACH_Fighter::ACH_Fighter() {
	SetGenericTeamId(FGenericTeamId(ETeamAttitude::Hostile));
	
}

void ACH_Fighter::Hit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OverlappedComponent->SetGenerateOverlapEvents(false);
	((ACH_Human*)OtherActor)->TakeHit(Weapons[wType].Damage,this);
}

void ACH_Fighter::SetWeapon(FWeapon Weapon)
{
	if (Weapons.Num() <= Weapon.Type) Weapons.SetNum(Weapon.Type + 1);
	Weapons[(uint8)Weapon.Type] = Weapon;
	switch (Weapon.Type)
	{
	case EWeaponType::Primary:
		wPrimary->SetStaticMesh(Weapons[1].Mesh);
		break;
	case EWeaponType::Secondary:
		wSecondary->SetStaticMesh(Weapons[2].Mesh);
		break;
	default:
		break;
	}
}

void ACH_Fighter::TakeHit(float damage, AActor* attacker)
{
	Super::TakeHit(damage, attacker);
	if (health > 0) {
		SendAlert();
	}
}

void ACH_Fighter::Attack()
{
	if (Ready) {
		Ready = false;
		PlayAnimMontage(AttackMontages[wType], 1.0f, cmbAttack[Combo]);
		Combo = (Combo >= cmbAttack.Num()-1) ? 0 : Combo + 1;
	}
}

void ACH_Fighter::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if (wPunch_L) {
		wPunch_L->AttachToComponent(GetMesh(), rules, "L_Punch");
		wPunch_L->SetCollisionProfileName(wCategory);
		wPunch_L->OnComponentBeginOverlap.AddDynamic(this, &ACH_Fighter::Hit);
	}
	if (wPunch_R) {
		wPunch_R->AttachToComponent(GetMesh(), rules, "R_Punch");
		wPunch_R->SetCollisionProfileName(wCategory);
		wPunch_R->OnComponentBeginOverlap.AddDynamic(this, &ACH_Fighter::Hit);
	}
	if (wPrimary) {
		wPrimary->AttachToComponent(GetMesh(), rules, "WS_Back_Primary");
		wPrimary->SetCollisionProfileName(wCategory);
		wPrimary->OnComponentBeginOverlap.AddDynamic(this, &ACH_Fighter::Hit);
	}
	if (wSecondary) {
		wSecondary->AttachToComponent(GetMesh(), rules, "WS_Back_Secondary");
	}
}