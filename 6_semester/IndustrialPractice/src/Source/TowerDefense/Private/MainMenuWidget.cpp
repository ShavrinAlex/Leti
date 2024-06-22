// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/KismetSystemLibrary.h"

bool UMainMenuWidget::Initialize()
{
	Super::Initialize();
	NewGameButton->OnClicked.AddDynamic(this, &UMainMenuWidget::NewGameButtonClicked);
	LoadGameButton->OnClicked.AddDynamic(this, &UMainMenuWidget::LoadGameButtonClicked);
	CloseGameButton->OnClicked.AddDynamic(this, &UMainMenuWidget::CloseGameButtonClicked);
	OptionGameButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OptionGameButtonClicked);

	//	levels.Add("GlobalMap");
	return true;
}

void UMainMenuWidget::NewGameButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("new game"));
	//	FString current = GetWorld()->GetMapName();
	//	current.RemoveFromStart(GetWorld()->StreamingLevelsPrefix);
	UGameplayStatics::OpenLevel(GetWorld(), FName("GlobalMap"));

}

void UMainMenuWidget::CloseGameButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("close game"));
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, false);
}

void UMainMenuWidget::LoadGameButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("load game"));
}

void UMainMenuWidget::OptionGameButtonClicked()
{

	UE_LOG(LogTemp, Warning, TEXT("option game"));
}

