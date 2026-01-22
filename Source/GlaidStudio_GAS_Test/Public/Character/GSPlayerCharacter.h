// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/GSBaseCharacterClass.h"
#include "GSPlayerCharacter.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class GLAIDSTUDIO_GAS_TEST_API AGSPlayerCharacter : public AGSBaseCharacterClass
{
	GENERATED_BODY()

public:
	
	
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

protected:

private:
	void InitAbilityActorInfo();
	
};
