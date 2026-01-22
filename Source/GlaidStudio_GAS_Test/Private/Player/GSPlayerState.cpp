// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/GSPlayerState.h"
#include "AbilitySystem/GSAbilitySystemComponent.h"
#include "AbilitySystem/GSAttributeSet.h"

AGSPlayerState::AGSPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UGSAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UGSAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AGSPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AGSPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}
