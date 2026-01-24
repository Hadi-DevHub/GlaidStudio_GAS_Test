// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/GSBaseCharacterClass.h"
#include "GSPlayerCharacter.generated.h"

struct FGameplayTag;
class UGameplayAbility;
class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;

UCLASS()
class GLAIDSTUDIO_GAS_TEST_API AGSPlayerCharacter : public AGSBaseCharacterClass
{
	GENERATED_BODY()

public:

	AGSPlayerCharacter();
	virtual void PossessedBy(AController* NewController) override;

protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	/** Combat Interface */

	virtual FVector GetCursorHitResult_Implementation() override;

private:

	/** Gameplay Ability Setup */

	void InitAbilityActorInfo();

	void OnBerserkTagChanged(const FGameplayTag Tag, int32 NewValue);

	/** Camera Setup */

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	TObjectPtr<UCameraComponent> PlayerCamera;
	
};
