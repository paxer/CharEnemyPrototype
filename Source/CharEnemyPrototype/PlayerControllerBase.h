// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "WidgetHealthBase.h"
#include "WidgetManaBase.h"
#include "PlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class CHARENEMYPROTOTYPE_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

public:
	// Reference HealthBar Asset in the Editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UWidgetHealthBase> HealthBarWidget;

	UWidgetHealthBase* HealthBar;

	// Reference HealthBar Asset in the Editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UWidgetManaBase> ManaBarWidget;

	UWidgetManaBase* ManaBar;

protected:
	// Called when the game starts or when spawned
	void BeginPlay() override;

private:
	void AddHealthBar();
	void AddManaBar();
};
