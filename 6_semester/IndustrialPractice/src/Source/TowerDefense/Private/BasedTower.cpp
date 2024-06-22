// Fill out your copyright notice in the Description page of Project Settings.


#include "BasedTower.h"

// Sets default values
ABasedTower::ABasedTower()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasedTower::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasedTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasedTower::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

