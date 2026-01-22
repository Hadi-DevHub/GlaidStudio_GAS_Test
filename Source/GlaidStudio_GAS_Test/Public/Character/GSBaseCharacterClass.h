
#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "GSBaseCharacterClass.generated.h"

class UGSAttributeSet;
class UGSAbilitySystemComponent;

UCLASS(Abstract)
class GLAIDSTUDIO_GAS_TEST_API AGSBaseCharacterClass : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AGSBaseCharacterClass();
	
	/** GAS component getters. */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
