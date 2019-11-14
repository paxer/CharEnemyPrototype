// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Components/CapsuleComponent.h"
#include "TimerManager.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Damage = 0.1;
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	UCapsuleComponent* Capsule = GetCapsuleComponent();
	if (Capsule)
	{
		Capsule->OnComponentBeginOverlap.AddDynamic(this, &AEnemyBase::BeginOverlap);
		Capsule->OnComponentEndOverlap.AddDynamic(this, &AEnemyBase::EndOverlap);
	}


	Player = Cast<APlayerBase>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	ChasePlayer();
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEnemyBase::ChasePlayer()
{
	if (Player)
	{
		AIController = Cast<AAIControllerBase>(GetController());
		if (AIController)
		{
			AIController->MoveToActor(Player);
		}
	}
}

void AEnemyBase::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FTimerDelegate TimerDel;
	TimerDel.BindUFunction(this, FName("ApplyDamage"), OtherActor);
	GetWorldTimerManager().SetTimer(ApplyDamageTimer, TimerDel, 1.0f, true);
}

void AEnemyBase::EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GetWorldTimerManager().ClearTimer(ApplyDamageTimer);
}

void AEnemyBase::ApplyDamage(AActor* Actor)
{
	auto Player = Cast<APlayerBase>(Actor);
	if (Player)
	{
		TSubclassOf<UDamageType> const ValidDamageTypeClass = TSubclassOf<UDamageType>(UDamageType::StaticClass());
		FDamageEvent DamageEvent(ValidDamageTypeClass);		
		Player->TakeDamage(Damage, DamageEvent, AIController, this);
	}
}
