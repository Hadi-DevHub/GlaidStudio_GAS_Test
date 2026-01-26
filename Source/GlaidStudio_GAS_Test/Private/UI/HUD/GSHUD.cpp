#include "UI/HUD/GSHUD.h"

#include "UI/Widget/GSUserWidget.h"
#include "UI/WidgetController/GSWidgetController.h"

UGSWidgetController* AGSHUD::CreateOrGetOverlayWidgetController(const FWidgetControllerParams& WidgetParams)
{
	if (GSOverlayWidgetController == nullptr)
	{
		UGSWidgetController* WidgetController = NewObject<UGSWidgetController>(this, GSOverlayWidgetControllerClass);
		WidgetController->SetWidgetControllerParams(WidgetParams);
	}

	return GSOverlayWidgetController;
}

void AGSHUD::InitOverlay(APlayerController* PlayerController, APlayerState* PlayerState,
	UAbilitySystemComponent* AbilitySystemComponent, UAttributeSet* AttributeSet)
{
	checkf(GSOverlayWidgetClass, TEXT("Overlay Widget Class uninitialized, please fill out WBP_GSHUD"));
	checkf(GSOverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class uninitialized, please fill out WBP_GSHUD"));

	//-----------------------------------------------//
	//    Setting Up The Overlay Widget Controller   //
	//-----------------------------------------------//

	// --- Membuat param untuk overlay widget controller
	FWidgetControllerParams WidgetParams(PlayerController, PlayerState, AbilitySystemComponent, AttributeSet);
	
	// --- Membuat param untuk overlay widget controller
	UGSWidgetController* WidgetController = CreateOrGetOverlayWidgetController(WidgetParams);
	
	//--------------------------------------//
	//		Setting Up The USER WIDGET      //
	//--------------------------------------//

	// --- Membuat Overlay widget baru dengan class Overlay Widget Class
	UUserWidget* UserWidget = NewObject<UUserWidget>(GetWorld(), GSOverlayWidgetClass);
	
	// --- Cast ke Overlay widget untuk memanggil fungsi SetWidgetController
	GSOverlayWidget = Cast<UGSUserWidget>(UserWidget);
	
	GSOverlayWidget->SetWidgetController(WidgetController);
	GSOverlayWidget->AddToViewport();
}
