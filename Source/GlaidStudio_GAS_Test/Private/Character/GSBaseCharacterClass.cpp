

#include "Character/GSBaseCharacterClass.h"

AGSBaseCharacterClass::AGSBaseCharacterClass()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AGSBaseCharacterClass::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGSBaseCharacterClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

