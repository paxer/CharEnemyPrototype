// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WidgetProgressBarBase.h"
#include "WidgetManaBase.generated.h"

/**
 * 
 */
UCLASS()
class CHARENEMYPROTOTYPE_API UWidgetManaBase : public UWidgetProgressBarBase
{
	GENERATED_BODY()
	
public:
	UWidgetManaBase();

	UFUNCTION()
	void ManaUpdated(float Mana);
};
