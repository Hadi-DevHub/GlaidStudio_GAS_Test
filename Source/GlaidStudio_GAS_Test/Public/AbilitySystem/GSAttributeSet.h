// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "GSAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class GLAIDSTUDIO_GAS_TEST_API UGSAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UGSAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UGSAttributeSet, Health)
	
	UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UGSAttributeSet, MaxMana)

	UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UGSAttributeSet, Mana)
	
	UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData MaxPower;
	ATTRIBUTE_ACCESSORS(UGSAttributeSet, MaxPower)

	UPROPERTY(BlueprintReadOnly, Category = "Combat Attributes")
	FGameplayAttributeData Power;
	ATTRIBUTE_ACCESSORS(UGSAttributeSet, Power)
	
	UPROPERTY(BlueprintReadOnly, Category = "Combat Attributes")
	FGameplayAttributeData MaxDefense;
	ATTRIBUTE_ACCESSORS(UGSAttributeSet, MaxDefense)

	UPROPERTY(BlueprintReadOnly, Category = "Combat Attributes")
	FGameplayAttributeData Defense;
	ATTRIBUTE_ACCESSORS(UGSAttributeSet, Defense)


protected:

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
};
