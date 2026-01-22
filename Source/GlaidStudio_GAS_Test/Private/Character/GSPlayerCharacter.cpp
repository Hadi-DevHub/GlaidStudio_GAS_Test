// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GSPlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "Player/GSPlayerState.h"

AGSPlayerCharacter::AGSPlayerCharacter()
{

}

void AGSPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	InitAbilityActorInfo();
}

void AGSPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AGSPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGSPlayerCharacter::InitAbilityActorInfo()
{
	AGSPlayerState* GSPlayerState = Cast<AGSPlayerState>(GetPlayerState());
	check(GSPlayerState);
	GSPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(GSPlayerState, this);
	AbilitySystemComponent = GSPlayerState->GetAbilitySystemComponent();
	AttributeSet = GSPlayerState->GetAttributeSet();
}

