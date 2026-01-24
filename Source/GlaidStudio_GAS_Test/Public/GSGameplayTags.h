#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "NativeGameplayTags.h"

namespace GSGameplayTags
{
	//-----------------//
	//	  Input Tags   //
	//-----------------//
	
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_LMB);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_SPACE);

	//-----------------//
	//	 Ability Tags  //
	//-----------------//
	
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_FireBall);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Berserk);
	
	//------------------//
	//	 Cooldown Tags  //
	//------------------//
	
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Cooldown_FireBall);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Cooldown_Berserk);
	
	//-----------------//
	//	   Cue Tags    //
	//-----------------//

	UE_DECLARE_GAMEPLAY_TAG_EXTERN(GameplayCue_Berserk);

}
	
