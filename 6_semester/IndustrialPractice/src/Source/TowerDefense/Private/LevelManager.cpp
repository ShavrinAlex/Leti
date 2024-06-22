// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelManager.h"
#include "EngineUtils.h"
#include "Engine/TargetPoint.h"
#include "Engine/Engine.h"
#include "EnemyMob.h"


// Sets default values
ALevelManager::ALevelManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->life = 10;
	this->money = 1000;
	this->graph = nullptr;
};

void ALevelManager::init_graph()
{
	TMap<int, TArray<int>> adjacency_list = {{1, TArray<int>{2}}, {2, TArray<int>{3, 4}}, {3, TArray<int>{5}}, {4, TArray<int>{6}},
	{5, TArray<int>{7}}, {6, TArray<int>{7}}, {7, TArray<int>{8}}, {8, TArray<int>{}}};
    this->graph = NewObject<URoadGraph>();
	this->graph->init(adjacency_list, 8, TArray<int>{1});

	TArray<ATargetPoint*> Targets;
	for (TActorIterator<ATargetPoint> It(GetWorld()); It; ++It)
	{
		ATargetPoint* TargetPoint = *It;
		Targets.Add(TargetPoint);
	}

	// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::FromInt(Targets.Num()));
	graph->SetLocations(Targets);

	// for (auto const& [key, val] : graph->nodes){
	// 	GEngine->AddOnScreenDebugMessage(-1, 100.f, FColor::Blue, FString::Printf(TEXT("Node: %d %d"), key, val->name));
	// 	for (auto node : val->children){
	// 		GEngine->AddOnScreenDebugMessage(-1, 100.f, FColor::Blue, FString::Printf(TEXT("Children: %d\nLocation: %f %f"), node->name, node->location.X, node->location.Y));
	// 	}
	// }
};

// Called when the game starts or when spawned
void ALevelManager::BeginPlay()
{
	Super::BeginPlay();
	
};

// Called every frame
void ALevelManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

};



