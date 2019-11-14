// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBase.h"

// Sets default values
APlayerBase::APlayerBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Health = 1.0;
}

// Called when the game starts or when spawned
void APlayerBase::BeginPlay()
{
	Super::BeginPlay();
	
	PlayerController = Cast<APlayerControllerBase>(Controller);	
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

float APlayerBase::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (!IsDead)
	{
		Health -= DamageAmount;
		UpdateHealthBar();

		if (Health <= 0.0)
		{
			IsDead = true;
			PlayerIsDead();
		}
	}

	return DamageAmount;
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

void APlayerBase::UpdateHealthBar()
{
	if (PlayerController)
	{
		auto HealthBar = PlayerController->HealthBar;
		if (HealthBar)
		{
			HealthBar->Update(Health);
		}
	}
}
