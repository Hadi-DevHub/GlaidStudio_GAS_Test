// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameplayTagContainer.h"
#include "GSPlayerController.generated.h"

class UGSAbilitySystemComponent;
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

	/** Set Input */
	virtual void SetupInputComponent() override;

	void TraceUnderCursor(FHitResult& UnderCursor);
	FVector GetHitUnderCursor() const { return UnderCursor.ImpactPoint; };

protected:

	/** Gameplay Ability Input */
	void OnAbilityInputTagPressed(FGameplayTag InputTag);
	void OnAbilityInputTagReleased(FGameplayTag InputTag);
	void OnAbilityInputTagHeld(FGameplayTag InputTag);

	/** Base Control Input */
	void Move(const FInputActionValue& InputActionValue);
	void Look(const FInputActionValue& InputActionValue);
	void Jump(const FInputActionValue& InputActionValue);
	
private:

	UGSAbilitySystemComponent* GetGS_ASC() const;

	/** Input Variables */

	UPROPERTY()
	FHitResult UnderCursor;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	float TraceDistance = 5000.f;
	
	UPROPERTY(EditDefaultsOnly, Category = Input)
	TObjectPtr<UInputMappingContext> GSMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	TObjectPtr<UInputAction> MoveInputAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	TObjectPtr<UInputAction> LookInputAction;

	UPROPERTY(EditAnywhere, Category = Input)
	float CameraSensitivity = 1.f;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	TObjectPtr<UGSInputConfig> InputConfig;
	
};

