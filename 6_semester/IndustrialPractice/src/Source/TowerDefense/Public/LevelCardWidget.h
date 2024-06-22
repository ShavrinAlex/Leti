// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LevelCardWidget.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API ULevelCardWidget : public UUserWidget
{
	GENERATED_BODY()

	class FString mission_name;

	virtual bool Initialize();

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TextBlockLevelCard;

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonA;

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonB;

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonC;

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonCloseCard;


	UPROPERTY(meta = (BindWidget))
	class UBorder* BorderLevelCard;

	UFUNCTION()
	void CloseCardButtonClicked();

	UFUNCTION()
	void AButtonClicked();

	UFUNCTION()
	void BButtonClicked();

	UFUNCTION(BlueprintCallable)
	void callCard();
};
