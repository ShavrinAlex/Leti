// Fill out your copyright notice in the Description page of Project Settings.




#include "MapActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "MyGameInstance.h"

// Sets default values
AMapActor::AMapActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));



	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);


}

void AMapActor::MeshMapClicked()
{

	UE_LOG(LogTemp, Warning, TEXT("%s"), *FString(levelName));

	GetWorld()->GetGameInstance<UMyGameInstance>()->setLevelName(*FString("Level" + levelName));
	GetWorld()->GetGameInstance<UMyGameInstance>()->currentLevelIndex = FCString::Atoi(*FString(levelName));
	GetWorld()->GetGameInstance<UMyGameInstance>()->isLevelClicked = true;

}

void AMapActor::setCustomMesh(UStaticMesh* customMesh)
{

	Mesh->SetStaticMesh(customMesh);

}

