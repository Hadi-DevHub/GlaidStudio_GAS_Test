

#include "Character/GSBaseCharacterClass.h"
#include "AbilitySystem/GSAbilitySystemComponent.h"
#include "Components/CapsuleComponent.h"

AGSBaseCharacterClass::AGSBaseCharacterClass()
{
	PrimaryActorTick.bCanEverTick = false;

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetCapsuleComponent()->SetGenerateOverlapEvents(false);
	
	GetMesh()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetMesh()->SetGenerateOverlapEvents(true);
}

UAbilitySystemComponent* AGSBaseCharacterClass::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AGSBaseCharacterClass::GetAttributeSet() const
{
	return AttributeSet;
}

void AGSBaseCharacterClass::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGSBaseCharacterClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGSBaseCharacterClass::GiveStartupAbilities() const 
{
	UGSAbilitySystemComponent* GS_ASC = Cast<UGSAbilitySystemComponent>(AbilitySystemComponent);
	if (GS_ASC)
	{
		GS_ASC->AddCharacterAbilities(StartupAbilities);
	}
}

FVector AGSBaseCharacterClass::GetCombatSocketLocation_Implementation()
{
	if (!CombatSocketName.IsValid()) return FVector();
	
	return GetMesh()->GetSocketLocation(CombatSocketName);
}


