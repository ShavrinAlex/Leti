// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameInstance.h"
#include "MissionWidget.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API UMissionWidget : public UUserWidget
{
	GENERATED_BODY()
	virtual bool Initialize();
	
	UFUNCTION(BlueprintCallable)
	void Update();

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonPause;

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonSpeed;


	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TextBlockSkills;


	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TextBlockLifes;


	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TextBlockWaves;


	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TextBlockMoney;

	UFUNCTION()
	void SpeedButtonClicked();

};
