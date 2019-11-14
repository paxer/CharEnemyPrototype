// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CHARENEMYPROTOTYPE_API AGModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	void BeginPlay() override;
};
