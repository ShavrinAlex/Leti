#pragma once
#include <utility>
#include <vector>
#include <iostream>


typedef std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>> myPair;


void processMatrices(const myPair& matrices);
template <typename QueueType>
void thConsumer(QueueType& queue, const int power) {
    myPair matrices;
    for (int i = 0; i < power; i++) {
        queue.pop(matrices);
        processMatrices(matrices);
        // std::cout << "Consumed: " << i << std::endl;
    }
};
