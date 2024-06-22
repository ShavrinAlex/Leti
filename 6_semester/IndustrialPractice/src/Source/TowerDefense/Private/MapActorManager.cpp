// Fill out your copyright notice in the Description page of Project Settings.


#include "MapActorManager.h"

// Sets default values
AMapActorManager::AMapActorManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMapActorManager::BeginPlay()
{
	Super::BeginPlay();

	levels.SetNumZeroed(levelAmount);

	for (int32 i = 0; i < levelAmount; i++) {


		TSubclassOf<AMapActor> newLvl = lvl;

		AMapActor* newLevel = GetWorld()->SpawnActor<AMapActor>(newLvl, FVector(FIntPoint(i * 250, 0)), FRotator::ZeroRotator);
		newLevel->levelName = FString::FromInt(i);
		newLevel->setCustomMesh(customMeshes[i]);
		levels[i] = newLevel;
	}
	
}

// Called every frame
void AMapActorManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

