// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelCardWidget.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "MyGameInstance.h"

bool ULevelCardWidget::Initialize()
{
	Super::Initialize();
	this->mission_name = "Level1";
	ButtonCloseCard->OnClicked.AddDynamic(this, &ULevelCardWidget::CloseCardButtonClicked);
	ButtonA->OnClicked.AddDynamic(this, &ULevelCardWidget::AButtonClicked);
	ButtonB->OnClicked.AddDynamic(this, &ULevelCardWidget::BButtonClicked);
	return true;
}

void ULevelCardWidget::CloseCardButtonClicked()
{
	BorderLevelCard->SetVisibility(ESlateVisibility::Hidden);
	ButtonA->SetVisibility(ESlateVisibility::Hidden);
	ButtonB->SetVisibility(ESlateVisibility::Hidden);
	ButtonC->SetVisibility(ESlateVisibility::Hidden);
	ButtonCloseCard->SetVisibility(ESlateVisibility::Hidden);
}

void ULevelCardWidget::AButtonClicked()
{



	//UMyGameInstance* game;
	//game->setLevelName();
	GetWorld()->GetGameInstance<UMyGameInstance>()->currentLevelDifficulty = "company";
	UGameplayStatics::OpenLevel(GetWorld(), FName(this->mission_name));

}

void ULevelCardWidget::BButtonClicked()
{



	//UMyGameInstance* game;
	//game->setLevelName();
	GetWorld()->GetGameInstance<UMyGameInstance>()->currentLevelDifficulty = "challenge";
	UGameplayStatics::OpenLevel(GetWorld(), FName(this->mission_name));

}

void ULevelCardWidget::callCard()
{
	BorderLevelCard->SetVisibility(ESlateVisibility::Visible);
	ButtonA->SetVisibility(ESlateVisibility::Visible);
	ButtonB->SetVisibility(ESlateVisibility::Visible);
	ButtonC->SetVisibility(ESlateVisibility::Visible);
	ButtonCloseCard->SetVisibility(ESlateVisibility::Visible);
	GetWorld()->GetGameInstance<UMyGameInstance>()->isLevelClicked = false;

	FString data = GetWorld()->GetGameInstance<UMyGameInstance>()->currentLevelName;
	TextBlockLevelCard->SetText(FText::FromString(data));

}
