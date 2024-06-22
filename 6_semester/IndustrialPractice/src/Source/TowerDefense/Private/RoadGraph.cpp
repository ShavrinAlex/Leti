// Fill out your copyright notice in the Description page of Project Settings.


#include "RoadGraph.h"
#include "Engine/Engine.h"


URoadGraph::URoadGraph()
{

};

void URoadGraph::init(TMap<int, TArray<int>> adjacency_list, int finish_node_number, TArray<int> starts_node_numbers)
{
    URoadNode* Node;
    for (auto const& [key, val] : adjacency_list) 
    {
        Node = NewObject<URoadNode>();
        Node->name = key;
        nodes.Add(key, Node);
    }

    for (auto const& [key, val] : adjacency_list) 
    {
        for (auto node : val) 
        {
            nodes[key]->children.Add(nodes[node]);
            nodes[node]->parents.Add(nodes[key]);
        }
    }

    this->finish = nodes[finish_node_number];
    
    for (auto node : starts_node_numbers)
    {
        this->starts.Add(nodes[node]);
    }
};

int cmp(URoadNode* A, URoadNode* B){
    return A->get_load_factor() < B->get_load_factor();
}

URoadNode* URoadGraph::get_best_start()
{
    // this->starts[0]->load_factors[static_cast<int>(SubNode::UP)] = 1;
    // std::sort(this->starts.begin(), this->starts.end(), cmp);
    return this->starts[0];
};

void URoadGraph::SetLocations(TArray<ATargetPoint*> Targets)
{
    for (ATargetPoint* Target : Targets)
    {
        FString TargetLabel = Target->GetActorLabel();
        FVector TargetLocation = Target->GetActorLocation();
        int NodeNumber = FCString::Atoi(*TargetLabel.Mid(11));
        FVector NodeLocation = TargetLocation;
        // FString::FromInt( NodeNumber)
        // GEngine->AddOnScreenDebugMessage(-1, 100.f, FColor::Yellow, FString::Printf(TEXT("%s %d Location: %f %f"), *TargetLabel, NodeNumber, TargetLocation.X, TargetLocation.Y));
        this->nodes[NodeNumber]->location = NodeLocation;
    }
};

URoadGraph::~URoadGraph()
{
};

