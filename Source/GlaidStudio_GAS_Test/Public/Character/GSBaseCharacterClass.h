
#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "Interface/CombatInterface.h"
#include "GSBaseCharacterClass.generated.h"

class UGameplayEffect;
class UGameplayAbility;
class UAbilitySystemComponent;
class UAttributeSet;

UCLASS(Abstract)
class GLAIDSTUDIO_GAS_TEST_API AGSBaseCharacterClass : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	AGSBaseCharacterClass();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	/** Gameplay Ability Section */

	void GiveStartupAbilities() const;
	void GiveStartupPassiveAbilities() const;
	void AddCharacterAttributes() const;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
	
	UPROPERTY(EditDefaultsOnly, Category = "GameplayAbility | Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "GameplayAbility | Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupPassiveAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "GameplayAbility | Attributes")
	TArray<TSubclassOf<UGameplayEffect>> StartupAttributes;

	/** Combat Interface */

	virtual FVector GetCombatSocketLocation_Implementation() override;
	
	UPROPERTY(EditDefaultsOnly, Category = "Character Information | Skeleton")
	FName CombatSocketName;

};
