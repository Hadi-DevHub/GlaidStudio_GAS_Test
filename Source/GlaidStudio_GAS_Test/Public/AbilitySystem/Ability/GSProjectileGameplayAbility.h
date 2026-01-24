#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Ability/GSGameplayAbility.h"
#include "GSProjectileGameplayAbility.generated.h"

class AGSProjectile;

UCLASS()
class GLAIDSTUDIO_GAS_TEST_API UGSProjectileGameplayAbility : public UGSGameplayAbility
{
	GENERATED_BODY()

public:

protected:

	UFUNCTION(BlueprintCallable, Category = "Projectile")
	AGSProjectile* SpawnProjectile(const FVector& ProjectileTargetLocation);

	UPROPERTY(EditDefaultsOnly, Category = "Ability | Projectile Properties")
	TSubclassOf<AGSProjectile> ProjectileClass;

};
