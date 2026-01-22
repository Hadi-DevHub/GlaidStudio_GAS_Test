// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GSGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class GLAIDSTUDIO_GAS_TEST_API UGSGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, Category = "Ability Input")
	FGameplayTag InputTag = FGameplayTag();
	
};
