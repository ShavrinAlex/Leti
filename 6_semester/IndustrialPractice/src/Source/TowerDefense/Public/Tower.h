// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Tower.generated.h"

UCLASS()
class TOWERDEFENSE_API ATower : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATower();
	UPROPERTY(BlueprintReadWrite)
	TArray<AActor*> guards;

	UFUNCTION(BlueprintCallable)
	void SetGuardsAmount(int amount);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
