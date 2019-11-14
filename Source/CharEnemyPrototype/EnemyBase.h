// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerBase.h"
#include "AIControllerBase.h"
#include "EnemyBase.generated.h"

UCLASS()
class CHARENEMYPROTOTYPE_API AEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyBase();
	APlayerBase* Player;
	AAIControllerBase* AIController;
	// Called every frame
	void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ChasePlayer();

protected:
	// Called when the game starts or when spawned
	void BeginPlay() override;
};
