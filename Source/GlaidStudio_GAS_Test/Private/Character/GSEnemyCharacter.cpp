// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GSEnemyCharacter.h"

#include "AbilitySystem/GSAbilitySystemComponent.h"
#include "AbilitySystem/GSAttributeSet.h"
#include "Components/CapsuleComponent.h"

AGSEnemyCharacter::AGSEnemyCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UGSAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UGSAttributeSet>("AttributeSet");

}

void AGSEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AGSEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
