// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GSPlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/GSPlayerState.h"

AGSPlayerCharacter::AGSPlayerCharacter()
{
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.f;

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>("PlayerCamera");
	PlayerCamera->SetupAttachment(CameraBoom);
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

