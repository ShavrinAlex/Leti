// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MobPlaceStructure.generated.h"

UCLASS()
class TOWERDEFENSE_API AMobPlaceStructure : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMobPlaceStructure();
	UPROPERTY()
	int max_unit_amount;
	float mob_distance;
	TArray<FVector> mobs_coords;

	UFUNCTION(BlueprintCallable)
	void CalculateCoords(FVector coord);

	UFUNCTION(BlueprintCallable)
	FVector GetCoordByNumber(int number);

	UFUNCTION(BlueprintCallable)
	void UpdateMaxUnitsAmount(int amount);
private:
	UFUNCTION(BlueprintCallable)
	void GenerateMobsCoords(FVector centre_coord);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
