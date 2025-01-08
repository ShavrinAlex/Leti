#pragma once
#include <utility>
#include <vector>
#include <iostream>
#include "../matrix/matrix_operations.hpp"
#include "../queue/lockFreeQueue.hpp"
#include <type_traits>


typedef std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>> myPair;


void processMatrices(const myPair& matrices);
template <typename QueueType>
void thConsumer(QueueType& queue, const int power, const int thNumber) {
    myPair matrices;
    for (int i = 0; i < power; i++) {
        if constexpr (std::is_same<QueueType, LockFreeQueue<myPair>>::value) {
            queue.pop(matrices, thNumber);
        } else {
            queue.pop(matrices);
        }
        
        // std::cout << ) <<" "<< thNumber << std::endl;
        // writeMatrixInFile("CA" + std::to_string(thNumber) + std::to_string(i) + ".txt", matrices.first);
        // writeMatrixInFile("CB" + std::to_string(thNumber) + std::to_string(i) + ".txt", matrices.second);
        processMatrices(matrices);
        // std::cout << "Consumed: " << i << std::endl;
    }
};
