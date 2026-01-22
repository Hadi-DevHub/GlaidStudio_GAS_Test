

#include "Character/GSBaseCharacterClass.h"

#include "AbilitySystem/GSAbilitySystemComponent.h"

AGSBaseCharacterClass::AGSBaseCharacterClass()
{
	PrimaryActorTick.bCanEverTick = false;
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
