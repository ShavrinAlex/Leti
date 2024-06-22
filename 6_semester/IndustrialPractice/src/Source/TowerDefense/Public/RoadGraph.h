// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RoadNode.h"
#include "Engine/TargetPoint.h"
#include "RoadGraph.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API URoadGraph : public UObject
{
	GENERATED_BODY()

public:
	URoadGraph();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyVariable")
    TMap<int, URoadNode*> nodes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyVariable")
    URoadNode* finish;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyVariable")
    TArray<URoadNode*> starts;

	UFUNCTION(BlueprintCallable, Category = "MyMethod" )
    URoadNode* get_best_start();

	void init(TMap<int, TArray<int>> adjacency_list, int finish, TArray<int> starts);
	void SetLocations(TArray<ATargetPoint*> Targets);

	~URoadGraph();	
};
