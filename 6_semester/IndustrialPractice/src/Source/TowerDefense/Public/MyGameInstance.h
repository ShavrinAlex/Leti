// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LevelStruct.h"
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString currentLevelName = "-1";

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int currentLevelIndex = -1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int lifes = 100;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int waves = 5;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int money = 1000;

	UPROPERTY()
	TArray<FMyLevel> levelsData = {
		FMyLevel(100,5,5,"no"),
		FMyLevel(200,15,35,"cool"),
		FMyLevel(300,25,25,"smth"),
		FMyLevel(400,35,15,"no smth")
	};



	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString skills = "smth";

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool isLevelClicked = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool isFail = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool isWin = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString currentLevelDifficulty;

	UFUNCTION(BlueprintCallable)
	void setLevelName(FString levelName);

};
