// Fill out your copyright notice in the Description page of Project Settings.


#include "SummonTimer.h"
#define PrintString(String) GEngine->AddOnScreenDebugMessage(-1,1.0f,FColor::White,String)
// Sets default values
ASummonTimer::ASummonTimer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASummonTimer::BeginPlay()
{
	Super::BeginPlay();
	//int index = GetWorld()->GetGameInstance<UMyGameInstance>()->currentLevelIndex;
	//tracker = GetWorld()->GetGameInstance<UMyGameInstance>()->levelsData[index].waves;
	
}
// Called every frame
void ASummonTimer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ASummonTimer::TimerExpired() {
	OnTimerExpired.Broadcast();
	PrintString(FString::Printf(TEXT("timer expired %d"), 1));
}

void ASummonTimer::SetDelay(int delay){
	this->summon_delay = delay;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ASummonTimer::TimerExpired, float(this->summon_delay), true, 0.5f);
}

