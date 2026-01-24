#include "Actor/GSProjectile.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "AbilitySystem/Ability/GSProjectileGameplayAbility.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGSProjectile::AGSProjectile()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SphereCollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereCollisionComponent");
	ProjectileNiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>("ProjectileNiagaraComponent");
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
}

void AGSProjectile::BeginPlay()
{
	Super::BeginPlay();

	SphereCollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AGSProjectile::OnSphereOverlap);
}

void AGSProjectile::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	bool bValidOverlap =
		OtherActor != GetOwner();
		
	if (bValidOverlap && HasAuthority())
	{
		if (UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(OtherActor))
		{
			TargetASC->ApplyGameplayEffectSpecToSelf(*DamageEffectSpecHandle.Data);
		}
		Destroy();
	}
}

void AGSProjectile::Destroyed()
{
	Super::Destroyed();
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), ImpactSFX, GetActorLocation());
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ImpactVFX, GetActorLocation());
}



