// Enjoy

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "wArrow.generated.h"

class UStaticMeshComponent;
UCLASS()
class THECONING_API AwArrow : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Category = Mesh, BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* mesh = nullptr;

private:
	float d;
	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	AwArrow();
	UFUNCTION(BlueprintCallable)
		void Shoot(float damage);
};
