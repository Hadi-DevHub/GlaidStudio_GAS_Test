#include "UI/HUD/GSHUD.h"

#include "UI/Widget/GSUserWidget.h"
#include "UI/WidgetController/GSOverlayWidgetController.h"
#include "UI/WidgetController/GSWidgetController.h"

UGSOverlayWidgetController* AGSHUD::CreateOrGetOverlayWidgetController(const FWidgetControllerParams& WidgetParams)
{
	if (GSOverlayWidgetController == nullptr)
	{
		UGSOverlayWidgetController* WidgetController = NewObject<UGSOverlayWidgetController>(this, GSOverlayWidgetControllerClass);
		WidgetController->SetWidgetControllerParams(WidgetParams);
		WidgetController->BindCallbacksToDependencies();
		return WidgetController;
	}

	return GSOverlayWidgetController;
}

void AGSHUD::InitOverlay(APlayerController* PlayerController, APlayerState* PlayerState,
	UAbilitySystemComponent* AbilitySystemComponent, UAttributeSet* AttributeSet)
{
	checkf(GSOverlayWidgetClass, TEXT("Overlay Widget Class uninitialized, please fill out WBP_GSHUD"));
	checkf(GSOverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class uninitialized, please fill out WBP_GSHUD"));

	//--------------------------------------//
	//		Setting Up The USER WIDGET      //
	//--------------------------------------//

	// --- Membuat Overlay widget baru dengan class Overlay Widget Class
	UUserWidget* UserWidget = NewObject<UUserWidget>(GetWorld(), GSOverlayWidgetClass);
	
	// --- Cast ke Overlay widget untuk memanggil fungsi SetWidgetController
	GSOverlayWidget = Cast<UGSUserWidget>(UserWidget);
	
	//-----------------------------------------------//
	//    Setting Up The Overlay Widget Controller   //
	//-----------------------------------------------//

	// --- Membuat param untuk overlay widget controller
	FWidgetControllerParams WidgetParams(PlayerController, PlayerState, AbilitySystemComponent, AttributeSet);
	
	// --- Membuat param untuk overlay widget controller
	UGSOverlayWidgetController* WidgetController = CreateOrGetOverlayWidgetController(WidgetParams);

	GSOverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialVitalValues();
	GSOverlayWidget->AddToViewport();
}
