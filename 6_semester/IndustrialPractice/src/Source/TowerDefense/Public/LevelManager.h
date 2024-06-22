// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoadGraph.h"
#include "LevelManager.generated.h"

UCLASS()
class TOWERDEFENSE_API ALevelManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int life;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int money;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyVariable")
	URoadGraph* graph; 

	UFUNCTION(BlueprintCallable, Category = "MyMethod")
	void init_graph();

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
