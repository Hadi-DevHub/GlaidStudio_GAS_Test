// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameplayTagContainer.h"
#include "GSPlayerController.generated.h"

struct FInputActionValue;
class UGSInputConfig;
class UInputAction;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class GLAIDSTUDIO_GAS_TEST_API AGSPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	/** Input */
	virtual void SetupInputComponent() override;

protected:

	/** Input */
	void OnAbilityInputTagPressed(FGameplayTag InputTag);
	void OnAbilityInputTagReleased(FGameplayTag InputTag);
	void OnAbilityInputTagHeld(FGameplayTag InputTag);
	
	void Move(const FInputActionValue& InputActionValue);
	
private:

	UPROPERTY(EditDefaultsOnly, Category = Input)
	TObjectPtr<UInputMappingContext> GSMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	TObjectPtr<UInputAction> MoveInputAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	TObjectPtr<UInputAction> LookInputAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	TObjectPtr<UGSInputConfig> InputConfig;
	
};

