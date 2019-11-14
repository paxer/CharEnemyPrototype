// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBase.h"

// Sets default values
APlayerBase::APlayerBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Health = 1.0f;
	Mana = 1.0f;
	SpellPower = 0.1f;
	MaxHealth = 1.0f;
}

// Called when the game starts or when spawned
void APlayerBase::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<APlayerControllerBase>(Controller);
	UpdateHealthBar();
	UpdateManaBar();
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
	PlayerInputComponent->BindAction("Spell", IE_Pressed, this, &APlayerBase::MakeSpell);
}

float APlayerBase::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (!IsDead)
	{
		Health -= DamageAmount;
		UpdateHealthBar();

		if (Health <= 0.0f)
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

void APlayerBase::MakeSpell()
{
	if (Mana >= 0.0)
	{
		Mana -= SpellPower;
		Health += SpellPower;
		Health = FMath::Clamp(Health, 0.0f, MaxHealth);
		UpdateHealthBar();
		UpdateManaBar();
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

void APlayerBase::UpdateManaBar()
{
	if (PlayerController)
	{
		auto ManaBar = PlayerController->ManaBar;
		if (ManaBar)
		{
			ManaBar->Update(Mana);
		}
	}
}
