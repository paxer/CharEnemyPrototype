// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerControllerBase.h"
#include "PlayerBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdateHealthSignature, float, UpdatedHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdateManaSignature, float, UpdatedMana);

UCLASS()
class CHARENEMYPROTOTYPE_API APlayerBase : public ACharacter
{
	GENERATED_BODY()

public:	
	FUpdateHealthSignature OnHealthUpdate;
	FUpdateManaSignature OnManaUpdate;
		
	// Sets default values for this character's properties
	APlayerBase();
	void MoveForward(float Value);
	void MoveRight(float Value);
	void MakeSpell();
	bool IsDead;

	UFUNCTION(BlueprintImplementableEvent, Category = "Player Events")
	void PlayerIsDead();
	
	APlayerControllerBase* PlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerAttributes, Meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerAttributes, Meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float Mana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerAttributes)
	float SpellPower;

	// Called every frame
	void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

protected:
	// Called when the game starts or when spawned
	void BeginPlay() override;

private:
	float MaxHealth;
	void UpdateHealthBar();
	void UpdateManaBar();
};
