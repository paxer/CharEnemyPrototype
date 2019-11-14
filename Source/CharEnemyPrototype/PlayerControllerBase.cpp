// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerBase.h"


// Called when the game starts or when spawned
void APlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();
	AddHealthBar();
	AddManaBar();
}

void APlayerControllerBase::AddHealthBar()
{
	if (HealthBarWidget)
	{
		HealthBar = CreateWidget<UWidgetHealthBase>(this, HealthBarWidget);

		if (HealthBar)
		{
			HealthBar->AddToViewport();
		}
	}
}

void APlayerControllerBase::AddManaBar()
{
	if (ManaBarWidget)
	{
		ManaBar = CreateWidget<UWidgetManaBase>(this, ManaBarWidget);

		if (ManaBar)
		{
			ManaBar->AddToViewport();
		}
	}
}
