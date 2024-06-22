// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FailMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API UFailMenuWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual bool Initialize();

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonAgain;

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonExit;

	UPROPERTY(meta = (BindWidget))
	class UBorder* BorderFail;

	UFUNCTION()
	void AgainButtonClicked();

	UFUNCTION()
	void ExitButtonClicked();

	UFUNCTION(BlueprintCallable)
	void callFailMenu();
	
};
