#include "wArrow.h"
#include "Components/StaticMeshComponent.h"
#include "Characters/CH_Human.h"

void AwArrow::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OverlappedComponent->SetGenerateOverlapEvents(false);
	((ACH_Human*)OtherActor)->TakeHit(d,this);
	Destroy();
}

void AwArrow::BeginPlay()
{
	Super::BeginPlay();
	mesh->OnComponentBeginOverlap.AddDynamic(this, &AwArrow::BeginOverlap);
}

AwArrow::AwArrow()
{
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

void AwArrow::Shoot(float damage)
{
	d = damage;
	mesh->SetGenerateOverlapEvents(true);
	DetachFromActor({ EDetachmentRule::KeepWorld,EDetachmentRule::KeepWorld,EDetachmentRule::KeepWorld,true });
	mesh->SetSimulatePhysics(true);
	mesh->SetAllPhysicsLinearVelocity(GetActorForwardVector() * 4000, false);
	SetLifeSpan(5.f);
}


