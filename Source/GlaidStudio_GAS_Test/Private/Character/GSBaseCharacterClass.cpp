

#include "Character/GSBaseCharacterClass.h"

AGSBaseCharacterClass::AGSBaseCharacterClass()
{
	PrimaryActorTick.bCanEverTick = true;

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

