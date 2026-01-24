// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GSAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class GLAIDSTUDIO_GAS_TEST_API UGSAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void AddCharacterAbilities(TArray<TSubclassOf<UGameplayAbility>> Abilities);
	void AddCharacterAttributes(TArray<TSubclassOf<UGameplayEffect>> Effects);

	void AbilityInputTagPressed(const FGameplayTag& InputTag);
	void AbilityInputTagReleased(const FGameplayTag& InputTag);
	void AbilityInputTagHeld(const FGameplayTag& InputTag);
	
};
