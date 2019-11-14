// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "WidgetProgressBarBase.generated.h"

/**
 * 
 */
UCLASS()
class CHARENEMYPROTOTYPE_API UWidgetProgressBarBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UProgressBar* ProgressBar;

	UFUNCTION(BlueprintCallable, Category = Attributes)
	void Update(float Value);
};
