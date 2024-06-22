// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SummonTimer.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTimerExpired);
UCLASS()
class TOWERDEFENSE_API ASummonTimer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASummonTimer();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//int32 tracker = 1;

private:
	int summon_delay;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void TimerExpired();

	FTimerHandle TimerHandle;

	UFUNCTION(BlueprintCallable)
	void SetDelay(int delay);
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Timer")
	FOnTimerExpired OnTimerExpired;
};
