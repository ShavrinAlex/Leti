// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "Mob.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API AMob : public APaperZDCharacter
{
	GENERATED_BODY()
public:
    AMob();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyVariable")
	FVector2D Directionality;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyVariable")
	int Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyVariable")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyVariable")
	bool IsDead;

    UFUNCTION(BlueprintCallable, Category="MyMethod")
	void UpdateDirectionality();

	// UFUNCTION(BlueprintCallable, Category="MyMethod")
	// bool isDead();

	void Tick(float DeltaSeconds) override;
};
