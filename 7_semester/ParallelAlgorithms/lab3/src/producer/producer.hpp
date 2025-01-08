#pragma once
#include <utility>
#include <vector>
#include <iostream>
#include "../matrix/matrix_operations.hpp"
#include "../queue/lockFreeQueue.hpp"
#include <type_traits>


typedef std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>> myPair;


myPair produceMatrices();
template <typename QueueType>
void thProducer(QueueType& queue, const int power, const int thNumber) {
    for (int i = 0; i < power; i++) {
        // std::cout << "Produce: " << i << std::endl;
        myPair matrices = produceMatrices();
        // writeMatrixInFile("A" + std::to_string(thNumber) + std::to_string(i) + ".txt", matrices.first);
        // writeMatrixInFile("B" + std::to_string(thNumber) + std::to_string(i) + ".txt", matrices.second);
        if constexpr (std::is_same<QueueType, LockFreeQueue<myPair>>::value) {
            queue.push(matrices, thNumber);
        } else {
            queue.push(matrices);
        }

        // std::cout << "Produced: " << i << std::endl;
    }
};
