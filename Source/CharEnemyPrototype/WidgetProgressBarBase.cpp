// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetProgressBarBase.h"

void UWidgetProgressBarBase::Update(float Value)
{
	if (ProgressBar)
	{		
		ProgressBar->SetPercent(Value);
	}
}
