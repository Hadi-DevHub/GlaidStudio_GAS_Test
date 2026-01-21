
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GSBaseCharacterClass.generated.h"

UCLASS()
class GLAIDSTUDIO_GAS_TEST_API AGSBaseCharacterClass : public ACharacter
{
	GENERATED_BODY()

public:
	AGSBaseCharacterClass();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
