// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyMob.h"


AEnemyMob::AEnemyMob()
{
    this->current_node = nullptr;
    this->sub_node = SubNode::MIDDLE;
    this->next_node = nullptr;
    // this->start_location = FVector(0, 0, 0);
};
