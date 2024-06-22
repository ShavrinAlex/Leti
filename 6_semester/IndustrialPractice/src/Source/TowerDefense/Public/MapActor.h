// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapActor.generated.h"

UCLASS()
class TOWERDEFENSE_API AMapActor : public AActor
{
	GENERATED_BODY()
public:
	AMapActor();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString levelName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int time = 0;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int points = 0;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool passed = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool avaible = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;



	UFUNCTION(BlueprintCallable, Category = "Mouse Input")
	void MeshMapClicked();

	UFUNCTION(BlueprintCallable, Category = "Mouse Input")
	void setCustomMesh(UStaticMesh* customMesh);

};
