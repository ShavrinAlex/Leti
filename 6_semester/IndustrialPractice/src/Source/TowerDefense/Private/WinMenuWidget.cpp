// Fill out your copyright notice in the Description page of Project Settings.


#include "WinMenuWidget.h"
#include "Components/Button.h"
#include "Components/Border.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "MyGameInstance.h"

bool UWinMenuWidget::Initialize()
{
	Super::Initialize();
	ButtonAgain->OnClicked.AddDynamic(this, &UWinMenuWidget::AgainButtonClicked);
	ButtonExit->OnClicked.AddDynamic(this, &UWinMenuWidget::ExitButtonClicked);
	return true;
}

void UWinMenuWidget::AgainButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("Mission"));
}

void UWinMenuWidget::ExitButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("GlobalMap"));
}

void UWinMenuWidget::callWinMenu()
{
	BorderWin->SetVisibility(ESlateVisibility::Visible);
	ButtonAgain->SetVisibility(ESlateVisibility::Visible);
	ButtonExit->SetVisibility(ESlateVisibility::Visible);
	//ButtonC->SetVisibility(ESlateVisibility::Visible);
	//ButtonCloseCard->SetVisibility(ESlateVisibility::Visible);
	GetWorld()->GetGameInstance<UMyGameInstance>()->isWin = false;
}

