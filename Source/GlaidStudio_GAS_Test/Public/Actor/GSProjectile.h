#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "GSProjectile.generated.h"

class UGSProjectileGameplayAbility;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnProjectileImpactSignature, const FVector&, OnProjectileImpact);

class UNiagaraComponent;
struct FGameplayEffectSpecHandle;
class UNiagaraSystem;
class USphereComponent;
class USoundBase;
class UProjectileMovementComponent;

UCLASS()
class GLAIDSTUDIO_GAS_TEST_API AGSProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AGSProjectile();

	/** Gameplay Ability Section */

	UPROPERTY(BlueprintReadWrite, meta = (ExposeOnSpawn = true), Category = "Gameplay Ability")
	FGameplayEffectSpecHandle DamageEffectSpecHandle;

protected:
	virtual void BeginPlay() override;
 	
	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void Destroyed() override;

	void OnHit();

private:

	/** Aesthetics Section */

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UNiagaraComponent> ProjectileNiagaraComponent;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UNiagaraSystem> ImpactVFX;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USoundBase> ImpactSFX;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> SphereCollisionComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;
	
};
