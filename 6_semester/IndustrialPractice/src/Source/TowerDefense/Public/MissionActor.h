// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MissionActor.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWaveExpired);
UCLASS()
class TOWERDEFENSE_API AMissionActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMissionActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	int32 tracker = 1;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void TimerFunction();

	FTimerHandle TimerHandle;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Timer")
	FOnWaveExpired OnWaveExpired;
};
