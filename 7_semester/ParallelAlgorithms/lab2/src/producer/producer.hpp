#pragma once
#include <utility>
#include <vector>
#include <iostream>


typedef std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>> myPair;


myPair produceMatrices();
template <typename QueueType>
void thProducer(QueueType& queue, const int power) {
    for (int i = 0; i < power; i++) {
        myPair matrices = produceMatrices();
        queue.push(matrices);
        // std::cout << "Produced: " << i << std::endl;
    }
};
