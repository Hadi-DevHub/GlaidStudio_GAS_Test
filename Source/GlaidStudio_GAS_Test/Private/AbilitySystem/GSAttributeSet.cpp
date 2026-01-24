// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GSAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"

void UGSAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
	}
	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxMana());
	}
}

void UGSAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		if (GetHealth() == 0)
		{
			ACharacter* Character = Cast<ACharacter>(Data.Target.GetAvatarActor());
			if(Character)
			{
				Character->GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Ignore);
				Character->GetMesh()->SetSimulatePhysics(true);
				Character->SetLifeSpan(3.f);
			}
		}
	}
}
