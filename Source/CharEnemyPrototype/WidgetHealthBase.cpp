// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetHealthBase.h"
#include "PlayerBase.h"
#include "Kismet/GameplayStatics.h"

UWidgetHealthBase::UWidgetHealthBase()
{
	auto Player = Cast<APlayerBase>(UGameplayStatics::GetActorOfClass(GetWorld(), APlayerBase::StaticClass()));
	if (Player != nullptr)
	{
		Player->OnHealthUpdate.AddDynamic(this, &UWidgetHealthBase::HealthUpdated);
	}
}

void UWidgetHealthBase::HealthUpdated(const float Health)
{
	Update(Health);
}
