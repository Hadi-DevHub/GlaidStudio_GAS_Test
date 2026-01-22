// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GSEnemyCharacter.h"

#include "AbilitySystem/GSAbilitySystemComponent.h"
#include "AbilitySystem/GSAttributeSet.h"

AGSEnemyCharacter::AGSEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<UGSAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<UGSAttributeSet>("GSAttributeSet");
}

void AGSEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
