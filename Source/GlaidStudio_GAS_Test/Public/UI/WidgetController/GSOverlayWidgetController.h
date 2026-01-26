// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/GSWidgetController.h"
#include "GameplayEffectTypes.h"
#include "GSOverlayWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChangedSignature, float, NewMana);

struct FOnAttributeChangeData;
class UAbilitySystemComponent;

UCLASS(BlueprintType, Blueprintable)
class GLAIDSTUDIO_GAS_TEST_API UGSOverlayWidgetController : public UGSWidgetController
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable, Category = "GAS | Attributes")
	FOnHealthChangedSignature OnHealthChanged;
	
	UPROPERTY(BlueprintAssignable, Category = "GAS | Attributes")
	FOnHealthChangedSignature OnMaxHealthChanged;
	
	UPROPERTY(BlueprintAssignable, Category = "GAS | Attributes")
	FOnManaChangedSignature OnManaChanged;
	
	UPROPERTY(BlueprintAssignable, Category = "GAS | Attributes")
	FOnManaChangedSignature OnMaxManaChanged;

	UFUNCTION(BlueprintCallable)
	virtual void BroadcastInitialVitalValues() override;
	virtual void BindCallbacksToDependencies() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bHasReceivedInitialVitalValues = false;

};
