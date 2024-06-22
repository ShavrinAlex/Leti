// Fill out your copyright notice in the Description page of Project Settings.


#include "MobPlaceStructure.h"
#include <iostream>
#include "Math/UnrealMathUtility.h"
// Sets default values
AMobPlaceStructure::AMobPlaceStructure()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->mob_distance = 80;
	this->max_unit_amount = 3;
	this->mobs_coords.SetNum(this->max_unit_amount);
}

// Called when the game starts or when spawned
void AMobPlaceStructure::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMobPlaceStructure::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMobPlaceStructure::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMobPlaceStructure::GenerateMobsCoords(FVector centre_coord){
	FVector mob_coord_vector;
	mob_coord_vector.Z = 0;
	float rotate_angle = 360/this->max_unit_amount;
	for (int i =0;i<this->max_unit_amount; i++){
		mob_coord_vector.X = centre_coord.X + cos(i*rotate_angle*PI/180)*this->mob_distance;
		mob_coord_vector.Y = centre_coord.Y + sin(i*rotate_angle*PI/180)*this->mob_distance;
		this->mobs_coords[i] = mob_coord_vector;
	}
	return;
}

void AMobPlaceStructure::CalculateCoords(FVector coord){
	this->GenerateMobsCoords(coord);
	return;
}

FVector AMobPlaceStructure::GetCoordByNumber(int number){
	return this->mobs_coords[number];
}

void AMobPlaceStructure::UpdateMaxUnitsAmount(int amount){
	this->max_unit_amount = amount;
	this->mobs_coords.SetNum(amount);
	return;
}