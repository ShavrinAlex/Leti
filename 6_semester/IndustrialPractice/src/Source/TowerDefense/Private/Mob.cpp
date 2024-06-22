// Fill out your copyright notice in the Description page of Project Settings.


#include "Mob.h"
#include "GameFramework/CharacterMovementComponent.h"

AMob::AMob()
{
    this->Directionality = FVector2D(1.0f, 0.0f);
    this->Health = 100;
    this->Speed = 100;
    this->IsDead = false;
    this->bUseControllerRotationYaw = false;
};

void AMob::UpdateDirectionality()
{
    FVector actor_directionality = this->GetVelocity();
    if (!actor_directionality.IsZero())
    {
        actor_directionality.Normalize(); 
        this->Directionality = FVector2D(-actor_directionality.X, actor_directionality.Y);
    }
};

// bool AMob::isDead()
// {
//     return this->Health <= 0;
// };

void AMob::Tick(float DeltaSeconds)
{
    Super::Tick( DeltaSeconds );
    
    this->UpdateDirectionality();
    GetCharacterMovement()->MaxWalkSpeed = this->Speed;
};
