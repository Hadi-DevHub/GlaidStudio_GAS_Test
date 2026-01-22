#include "Character/GSPlayerCharacter.h"
#include "AbilitySystem/GSAbilitySystemComponent.h"
#include "AbilitySystem/GSAttributeSet.h"
#include "Player/GSPlayerState.h"

void AGSPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitAbilityActorInfo();
}

void AGSPlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
}

void AGSPlayerCharacter::InitAbilityActorInfo()
{
	AGSPlayerState* GSPlayerState = Cast<AGSPlayerState>(GetPlayerState());
	check(GSPlayerState);
	GSPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(GSPlayerState, this);
	AbilitySystemComponent = GSPlayerState->GetAbilitySystemComponent();
	AttributeSet = GSPlayerState->GetAttributeSet();
}
