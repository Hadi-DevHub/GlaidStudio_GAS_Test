#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GSWidgetController.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
class UGSWidgetController;

USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
	GENERATED_BODY();
	
	FWidgetControllerParams(){}
	FWidgetControllerParams(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
		: PlayerController(PC), PlayerState(PS), AbilitySystemComponent(ASC), AttributeSet(AS){}

	UPROPERTY()
	APlayerController* PlayerController = nullptr;

	UPROPERTY()
	APlayerState* PlayerState = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* AbilitySystemComponent = nullptr;

	UPROPERTY()
	UAttributeSet* AttributeSet = nullptr;
	
};

UCLASS()
class GLAIDSTUDIO_GAS_TEST_API UGSWidgetController : public UObject
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable)
	void SetWidgetControllerParams(const FWidgetControllerParams& WCParams);

protected:
	
	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	APlayerController* PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	APlayerState* PlayerState = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	UAbilitySystemComponent* AbilitySystemComponent = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	UAttributeSet* AttributeSet = nullptr;
	
};
