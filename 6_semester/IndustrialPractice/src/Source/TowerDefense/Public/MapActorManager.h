// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapActor.h"
#include "MapActorManager.generated.h"

UCLASS()
class TOWERDEFENSE_API AMapActorManager : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	AMapActorManager();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 levelAmount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TArray<UStaticMesh*> customMeshes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TArray<AMapActor*> levels;



	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<AMapActor> lvl;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
