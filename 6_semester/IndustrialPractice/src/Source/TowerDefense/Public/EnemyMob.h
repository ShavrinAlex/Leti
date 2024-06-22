// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mob.h"
#include "RoadNode.h"
#include "EnemyMob.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API AEnemyMob : public AMob
{
	GENERATED_BODY()

public:
	AEnemyMob();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyVariable")
	URoadNode* current_node;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyVariable")
	URoadNode* next_node;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyVariable")
	SubNode sub_node;

	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyVariable")
	// FVector start_location;
};
