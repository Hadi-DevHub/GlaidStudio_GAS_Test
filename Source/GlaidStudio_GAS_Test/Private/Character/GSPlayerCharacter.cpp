// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GSPlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "GSGameplayTags.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/GSPlayerController.h"
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
	GiveStartupAbilities();
	AddCharacterAttributes();
	AbilitySystemComponent->RegisterGameplayTagEvent(GSGameplayTags::Ability_Berserk, EGameplayTagEventType::NewOrRemoved).AddUObject(this, &AGSPlayerCharacter::OnBerserkTagChanged);
}

void AGSPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGSPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FVector AGSPlayerCharacter::GetCursorHitResult_Implementation()
{
	AGSPlayerController* PlayerController = Cast<AGSPlayerController>(GetController());
	return PlayerController->GetHitUnderCursor();
}

void AGSPlayerCharacter::InitAbilityActorInfo()
{
	AGSPlayerState* GSPlayerState = Cast<AGSPlayerState>(GetPlayerState());
	check(GSPlayerState);
	GSPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(GSPlayerState, this);
	AbilitySystemComponent = GSPlayerState->GetAbilitySystemComponent();
	AttributeSet = GSPlayerState->GetAttributeSet();
}

void AGSPlayerCharacter::OnBerserkTagChanged(const FGameplayTag Tag, int32 NewValue)
{
	if (NewValue == 0)
	{
		AbilitySystemComponent->RemoveGameplayCue(GSGameplayTags::GameplayCue_Berserk);
	}
}
