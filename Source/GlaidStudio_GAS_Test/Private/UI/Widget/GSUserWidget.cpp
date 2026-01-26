#include "UI/Widget/GSUserWidget.h"

#include "UI/WidgetController/GSWidgetController.h"

void UGSUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
