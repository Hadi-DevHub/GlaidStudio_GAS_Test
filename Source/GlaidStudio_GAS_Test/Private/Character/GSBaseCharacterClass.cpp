

#include "Character/GSBaseCharacterClass.h"

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

