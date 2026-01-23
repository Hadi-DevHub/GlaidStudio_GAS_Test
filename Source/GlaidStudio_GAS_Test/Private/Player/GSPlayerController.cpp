// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/GSPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "Input/GSEnhancedInputComponent.h"


void AGSPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(GSMappingContext);
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(GSMappingContext, 0);
	}
}

void AGSPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	checkf(InputComponent, TEXT("Can't find InputComponent"));
	UGSEnhancedInputComponent* GSInputComponent = CastChecked<UGSEnhancedInputComponent>(InputComponent);
	GSInputComponent->BindAbilityActions(InputConfig,
		this,
		&AGSPlayerController::OnAbilityInputTagPressed,
		&AGSPlayerController::OnAbilityInputTagReleased,
		&AGSPlayerController::OnAbilityInputTagHeld);

	GSInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &AGSPlayerController::Move);
	GSInputComponent->BindAction(LookInputAction, ETriggerEvent::Triggered, this, &AGSPlayerController::Look);
}

void AGSPlayerController::OnAbilityInputTagPressed(FGameplayTag InputTag)
{
	GEngine->AddOnScreenDebugMessage(0, 2.f, FColor::Yellow, *InputTag.ToString());
}

void AGSPlayerController::OnAbilityInputTagReleased(FGameplayTag InputTag)
{
	GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Green, *InputTag.ToString());
}

void AGSPlayerController::OnAbilityInputTagHeld(FGameplayTag InputTag)
{
	GEngine->AddOnScreenDebugMessage(2, 2.f, FColor::Blue, *InputTag.ToString());
}

void AGSPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputVector2D = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.0f);

	const FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector Right = FRotationMatrix(Rotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn())
	{
		ControlledPawn->AddMovementInput(Forward, InputVector2D.Y);
		ControlledPawn->AddMovementInput(Right, InputVector2D.X);
	}
}

void AGSPlayerController::Look(const FInputActionValue& InputActionValue)
{
	const FVector2D InputVector2D = InputActionValue.Get<FVector2D>();

	GetPawn()->AddControllerYawInput(InputVector2D.X * CameraSensitivity);
	GetPawn()->AddControllerPitchInput(InputVector2D.Y * CameraSensitivity);
}



