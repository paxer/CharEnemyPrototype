// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WidgetProgressBarBase.h"
#include "WidgetHealthBase.generated.h"


UCLASS()
class CHARENEMYPROTOTYPE_API UWidgetHealthBase : public UWidgetProgressBarBase
{
	GENERATED_BODY()

	

public:

	UWidgetHealthBase();
	
	UFUNCTION()
	void HealthUpdated(float Health);
};
