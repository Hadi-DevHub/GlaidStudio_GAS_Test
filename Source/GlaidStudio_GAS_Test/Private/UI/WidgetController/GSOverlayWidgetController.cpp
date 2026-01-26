#include "UI/WidgetController/GSOverlayWidgetController.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectTypes.h"
#include "AbilitySystem/GSAttributeSet.h"

void UGSOverlayWidgetController::BroadcastInitialVitalValues()
{
	if (bHasReceivedInitialVitalValues) return;
	if (UGSAttributeSet* AS = CastChecked<UGSAttributeSet>(AttributeSet))
	{
		OnHealthChanged.Broadcast(AS->GetHealth());
		//GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Yellow, FString::Printf(TEXT("Health: %f"), AS->GetHealth()));
		
		OnMaxHealthChanged.Broadcast(AS->GetMaxHealth());
		//GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Yellow, FString::Printf(TEXT("MaxHealth: %f"), AS->GetMaxHealth()));

		OnManaChanged.Broadcast(AS->GetMana());
		//GEngine->AddOnScreenDebugMessage(2, 5.f, FColor::Yellow, FString::Printf(TEXT("Mana: %f"), AS->GetMana()));

		OnMaxManaChanged.Broadcast(AS->GetMaxMana());
		//GEngine->AddOnScreenDebugMessage(3, 5.f, FColor::Yellow, FString::Printf(TEXT("MaxMana: %f"), AS->GetMaxMana()));
	}
}

void UGSOverlayWidgetController::BindCallbacksToDependencies()
{
	if (UGSAttributeSet* AS = CastChecked<UGSAttributeSet>(AttributeSet))
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AS->GetHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnHealthChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AS->GetMaxHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnMaxHealthChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AS->GetManaAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnManaChanged.Broadcast(Data.NewValue);
		});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AS->GetMaxManaAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnMaxManaChanged.Broadcast(Data.NewValue);
		});}
	
}
