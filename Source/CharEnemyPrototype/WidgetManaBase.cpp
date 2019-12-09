// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetManaBase.h"
#include "PlayerBase.h"
#include "Kismet/GameplayStatics.h"

UWidgetManaBase::UWidgetManaBase()
{
	auto Player = Cast<APlayerBase>(UGameplayStatics::GetActorOfClass(GetWorld(), APlayerBase::StaticClass()));
	if (Player != nullptr)
	{
		Player->OnManaUpdate.AddDynamic(this, &UWidgetManaBase::ManaUpdated);
	}
}

void UWidgetManaBase::ManaUpdated(float Mana)
{
	Update(Mana);
}
