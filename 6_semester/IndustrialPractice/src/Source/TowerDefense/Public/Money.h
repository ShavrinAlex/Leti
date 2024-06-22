// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "Money.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API AMoney : public APaperZDCharacter
{
	GENERATED_BODY()

public:
	AMoney();

	UPROPERTY(BlueprintReadWrite, Category="MyVariable")
	int Value;

	UFUNCTION(BlueprintCallable, Category="MyMethod")
	void AddMoneyToLevelManager();
};
