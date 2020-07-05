// Enjoy


#include "CH_Melee.h"

ACH_Melee::ACH_Melee()
{
	wType = EWeaponType::Primary;
	wPrimary = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("wPrimary"));
}

void ACH_Melee::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	wPrimary->AttachToComponent(GetMesh(), rules, "WS_Hand_Primary");
}
void ACH_Melee::BeginPlay()
{
	Super::BeginPlay();
}

