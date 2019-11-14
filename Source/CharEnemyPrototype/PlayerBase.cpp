// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBase.h"
#include "PlayerControllerBase.h"

// Sets default values
APlayerBase::APlayerBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerBase::BeginPlay()
{
	Super::BeginPlay();

	// TODO: move to the appropriate method 
	APlayerControllerBase* PlayerController = Cast<APlayerControllerBase>(Controller);
	if (PlayerController)
	{
		auto HealthBar = PlayerController->HealthBar;
		if (HealthBar)
		{
			HealthBar->Update(0.5);
		}
	}
}

// Called every frame
void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &APlayerBase::MoveForward);
	PlayerInputComponent->BindAxis("Strafe", this, &APlayerBase::MoveRight);
}

void APlayerBase::MoveForward(float Value)
{
	if (Controller && Value)
	{
		const FVector Fwd = GetActorForwardVector();
		AddMovementInput(Fwd, Value);
	}
}

void APlayerBase::MoveRight(float Value)
{
	if (Controller && Value)
	{
		const FVector Right = GetActorRightVector();
		AddMovementInput(Right, Value);
	}
}
