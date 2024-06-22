// Fill out your copyright notice in the Description page of Project Settings.


#include "Money.h"
#include "LevelManager.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


AMoney::AMoney()
{
    Value = 10;
};

void AMoney::AddMoneyToLevelManager()
{
    TArray<AActor *> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ALevelManager::StaticClass(), FoundActors);
    ALevelManager* level_manager = Cast<ALevelManager>(FoundActors[0]);
    if (level_manager)
    {
        level_manager->money += Value;
    }
};
