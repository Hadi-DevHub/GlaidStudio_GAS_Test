// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../../../../../../Program Files/Epic Games/UE_5.4/Engine/Plugins/Animation/ACLPlugin/Source/ThirdParty/acl/external/rtm/includes/rtm/constants.h"
#include "Character/GSBaseCharacterClass.h"
#include "GSEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GLAIDSTUDIO_GAS_TEST_API AGSEnemyCharacter : public AGSBaseCharacterClass
{
	GENERATED_BODY()

public:
	AGSEnemyCharacter();
	
protected:
	virtual void BeginPlay() override;

private:
	
};
