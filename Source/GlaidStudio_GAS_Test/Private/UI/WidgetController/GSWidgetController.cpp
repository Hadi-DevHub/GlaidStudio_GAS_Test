#include "UI/WidgetController/GSWidgetController.h"

void UGSWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	
	PlayerState = WCParams.PlayerState;
	
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	
	AttributeSet = WCParams.AttributeSet;
}
