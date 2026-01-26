#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GSUserWidget.generated.h"


UCLASS()
class GLAIDSTUDIO_GAS_TEST_API UGSUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BLueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
	
protected:

	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
	
};
