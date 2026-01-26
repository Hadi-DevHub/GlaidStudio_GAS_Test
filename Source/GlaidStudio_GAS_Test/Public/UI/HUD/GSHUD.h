#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GSHUD.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
class UGSUserWidget;
class UGSWidgetController;
struct FWidgetControllerParams;

UCLASS()
class GLAIDSTUDIO_GAS_TEST_API AGSHUD : public AHUD
{
	GENERATED_BODY()
	
public:

	UGSWidgetController* CreateOrGetOverlayWidgetController(const FWidgetControllerParams& WidgetParams);

	void InitOverlay(APlayerController* PlayerController, APlayerState* PlayerState, UAbilitySystemComponent* AbilitySystemComponent, UAttributeSet* AttributeSet);

private:
	
	UPROPERTY()
	TObjectPtr<UGSUserWidget> GSOverlayWidget;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UGSUserWidget> GSOverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UGSWidgetController> GSOverlayWidgetController;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UGSWidgetController> GSOverlayWidgetControllerClass;
	
	
};
