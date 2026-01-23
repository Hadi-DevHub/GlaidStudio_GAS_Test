#include "AbilitySystem/Ability/GSProjectileGameplayAbility.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "Actor/GSProjectile.h"
#include "Interface/CombatInterface.h"

void UGSProjectileGameplayAbility::SpawnProjectile(const FVector& ProjectileTargetLocation)
{
	if (ProjectileClass == nullptr) return;

	const FVector CombatSocketLocation = ICombatInterface::Execute_GetCombatSocketLocation(GetAvatarActorFromActorInfo());
	const FRotator Rotation = (ProjectileTargetLocation - CombatSocketLocation).Rotation();
	FTransform SpawnTransform;
	SpawnTransform.SetLocation(CombatSocketLocation);
	SpawnTransform.SetRotation(Rotation.Quaternion());
	
	AGSProjectile* Projectile = GetWorld()->SpawnActorDeferred<AGSProjectile>(
		ProjectileClass,
		SpawnTransform,
		GetAvatarActorFromActorInfo(),
		Cast<APawn>(GetOwningActorFromActorInfo()),
		ESpawnActorCollisionHandlingMethod::AlwaysSpawn
		);

	UAbilitySystemComponent* SourceASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetAvatarActorFromActorInfo());
	FGameplayEffectContextHandle EffectContext = SourceASC->MakeEffectContext();
	FGameplayEffectSpecHandle EffectHandle = SourceASC->MakeOutgoingSpec(AssociatedGameplayEffect, GetAbilityLevel(), EffectContext);

	Projectile->DamageEffectSpecHandle = EffectHandle;
	Projectile->FinishSpawning(SpawnTransform);
}
