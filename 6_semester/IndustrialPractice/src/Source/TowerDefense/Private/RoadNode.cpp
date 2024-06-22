// Fill out your copyright notice in the Description page of Project Settings.


#include "RoadNode.h"
#include <numeric>


URoadNode::URoadNode()
{
    this->name = 0;
    this->location = FVector(0, 0, 0);
    this->load_factors = {0, 0, 0};
    this->parents = {};
    this->children = {};
};

URoadNode* URoadNode::get_best_child()
{   
    return this->children[0];
};

int URoadNode::get_load_factor() const
{
    return std::accumulate(this->load_factors.begin(), this->load_factors.end(), 0);
};

SubNode URoadNode::get_best_sub_node()
{
    TArray<SubNode> AllValues = { SubNode::UP, SubNode::MIDDLE, SubNode::DOWN };
    int32 RandomIndex = FMath::RandRange(0, AllValues.Num() - 1);
    return AllValues[RandomIndex];
};

URoadNode::~URoadNode()
{
}
