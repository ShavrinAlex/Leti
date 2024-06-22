// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RoadNode.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class SubNode : uint8
{
    UP = 0 UMETA(DisplayName = "UP"),
    MIDDLE = 1 UMETA(DisplayName = "MIDDLE"),
    DOWN = 2 UMETA(DisplayName = "DOWN")
};

UCLASS()
class TOWERDEFENSE_API URoadNode : public UObject
{
	GENERATED_BODY()

public:
	URoadNode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyVariable")
	int name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyVariable")
	FVector location;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyVariable")
	TArray<int> load_factors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyVariable")
	TArray<URoadNode*> parents;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyVariable")
	TArray<URoadNode*> children;

	UFUNCTION(BlueprintCallable, Category = "MyMethod")
    URoadNode* get_best_child();

	UFUNCTION(BlueprintCallable, Category = "MyMethod")
    int get_load_factor() const;

	UFUNCTION(BlueprintCallable, Category = "MyMethod")
	SubNode get_best_sub_node();

	~URoadNode();
};
