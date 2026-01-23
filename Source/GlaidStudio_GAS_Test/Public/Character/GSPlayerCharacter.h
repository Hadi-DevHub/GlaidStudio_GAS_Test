// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/GSBaseCharacterClass.h"
#include "GSPlayerCharacter.generated.h"

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

private:
	void InitAbilityActorInfo();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	TObjectPtr<UCameraComponent> PlayerCamera;
	
};
