// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	virtual bool Initialize();

	UPROPERTY(meta = (BindWidget))
	class UButton* NewGameButton;

	UFUNCTION()
	void NewGameButtonClicked();

	UPROPERTY(meta = (BindWidget))
	class UButton* CloseGameButton;

	UFUNCTION()
	void CloseGameButtonClicked();

	UPROPERTY(meta = (BindWidget))
	class UButton* LoadGameButton;

	UFUNCTION()
	void LoadGameButtonClicked();

	UPROPERTY(meta = (BindWidget))
	class UButton* OptionGameButton;

	UFUNCTION()
	void OptionGameButtonClicked();

	TArray<FString> levels;
};
