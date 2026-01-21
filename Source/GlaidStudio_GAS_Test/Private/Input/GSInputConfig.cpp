// Fill out your copyright notice in the Description page of Project Settings.


#include "Input/GSInputConfig.h"

const UInputAction* UGSInputConfig::FindInputActionForTag(const FGameplayTag& InputTag) const
{
	for (const FGSInputAction& Action : InputActions)
	{
		if (Action.InputTag.MatchesTagExact(InputTag))
		{
			return Action.InputAction;
		}
	}
	return nullptr;
}
