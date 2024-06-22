// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelStruct.generated.h"
/**
 * 
 */
//class TOWERDEFENSE_API LevelStruct
//{
//public:
//	LevelStruct();
//	~LevelStruct();
//};

USTRUCT()
struct FMyLevel
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	int32 lifes;

	UPROPERTY()
	int32 waves;

	UPROPERTY()
	int32 money;

	UPROPERTY()
	FString skills;

	FMyLevel() {
	}
	FMyLevel(int32 lifes, int32 waves, int32 money, FString skills) {
		this->lifes = lifes;
		this->waves = waves;
		this->money = money;
		this->skills = skills;
	}
};