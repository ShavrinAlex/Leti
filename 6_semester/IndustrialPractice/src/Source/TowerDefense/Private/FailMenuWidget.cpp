// Fill out your copyright notice in the Description page of Project Settings.


#include "FailMenuWidget.h"
#include "Components/Button.h"
#include "Components/Border.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "MyGameInstance.h"

bool UFailMenuWidget::Initialize()
{
	Super::Initialize();
	ButtonAgain->OnClicked.AddDynamic(this, &UFailMenuWidget::AgainButtonClicked);
	ButtonExit->OnClicked.AddDynamic(this, &UFailMenuWidget::ExitButtonClicked);
	return true;
}

void UFailMenuWidget::AgainButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("Mission"));
}

void UFailMenuWidget::ExitButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("GlobalMap"));
}

void UFailMenuWidget::callFailMenu()
{
	BorderFail->SetVisibility(ESlateVisibility::Visible);
	ButtonAgain->SetVisibility(ESlateVisibility::Visible);
	ButtonExit->SetVisibility(ESlateVisibility::Visible);
	//ButtonC->SetVisibility(ESlateVisibility::Visible);
	//ButtonCloseCard->SetVisibility(ESlateVisibility::Visible);
	GetWorld()->GetGameInstance<UMyGameInstance>()->isFail = false;
}
