// Fill out your copyright notice in the Description page of Project Settings.


#include "MissionActor.h"
#include "MyGameInstance.h"
#define PrintString(String) GEngine->AddOnScreenDebugMessage(-1,1.0f,FColor::White,String)
// Sets default values
AMissionActor::AMissionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AMissionActor::BeginPlay()
{
	Super::BeginPlay();
	int index = GetWorld()->GetGameInstance<UMyGameInstance>()->currentLevelIndex;
	tracker = GetWorld()->GetGameInstance<UMyGameInstance>()->levelsData[index].waves;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMissionActor::TimerFunction, 15.0f, true, 0.5f);
}
void AMissionActor::TimerFunction() {
	OnWaveExpired.Broadcast();
	tracker--;
	if (tracker == 0) {
		UE_LOG(LogTemp, Warning, TEXT("finish"));
		GetWorldTimerManager().ClearTimer(TimerHandle);
		GetWorld()->GetGameInstance<UMyGameInstance>()->isFail = true;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("timer Called"));
	}

	PrintString(FString::Printf(TEXT("calls remaining %d"), tracker));
}
// Called every frame
void AMissionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

