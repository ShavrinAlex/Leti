#include "matrix_operations.hpp"
#include <thread>
#include <fstream>
#include <random>
#include <iostream>


std::vector<std::vector<int>> generateMatrix(const int rows, const int columns, const int maxValue) {
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(columns));

    std::random_device random_device; 
    std::mt19937 gen(random_device()); 
    std::uniform_int_distribution<> uniform_distribution(-maxValue, maxValue);

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            matrix[i][j] = uniform_distribution(gen);
        }
    }

    return matrix;
}


std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int rowsA = A.size();
    int columnsA = A[0].size();
    int columnsB = B[0].size();
    std::vector<std::vector<int>> result(rowsA, std::vector<int>(columnsB, 0));

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsB; j++) {
            for (int k = 0; k < columnsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}


void thMultiplyMatrixBlock(const std::vector<std::vector<int>>& matrixA, const std::vector<std::vector<int>>& matrixB, std::vector<std::vector<int>>& result, std::vector<std::pair<int, int>> blockPositions) {
    for (int i = 0; i < blockPositions.size(); i++){
        for (int j = 0; j < matrixB.size(); j++) {
            result[blockPositions[i].first][blockPositions[i].second] += matrixA[blockPositions[i].first][j] * matrixB[j][blockPositions[i].second];
        }
    }
}


void multiplyMatricesByBlocks(const std::vector<std::vector<int>>& matrixA, const std::vector<std::vector<int>>& matrixB, std::vector<std::vector<int>>& result, const int threadsAmount) {
    int rowsA = matrixA.size();
    int columnsB = matrixB[0].size();

    int blockSize = std::ceil((double)rowsA * columnsB / threadsAmount);
    std::vector<std::pair<int,int>> blockPositions;
    std::vector<std::thread> threads;

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsB; j++) {
            blockPositions.push_back(std::pair(i,j));
            if (blockPositions.size() == blockSize || (i + 1 == rowsA && j + 1 == columnsB)) {
                threads.push_back(std::thread(thMultiplyMatrixBlock, std::ref(matrixA), std::ref(matrixB), std::ref(result), blockPositions));
                blockPositions.clear();
            }
        }
    }

    for (auto& thread : threads) {
        thread.join();
    }
}


void writeMatrixInFile(const std::string& filename, const std::vector<std::vector<int>>& result) {
    std::ofstream outputFile(filename);

    if (!outputFile.is_open())
    {
        std::cerr << "Open file err: " << filename << std::endl;
        exit(-1);
    }

    for (const auto& row : result) {
        for (const auto& val : row) {
            outputFile << val << " ";
        }
        outputFile << std::endl;
    }
    outputFile.close();
}


void printMatrix(const std::vector<std::vector<int>>& result) {
    for (const auto& row : result) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}
