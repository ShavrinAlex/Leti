#pragma once
#include <vector>
#include <string>


#define ROWS_A 10
#define COLUMNS_A 10
#define ROWS_B 10 
#define COLUMNS_B 10
#define RESULT_FILE "result.txt"
#define THREADS_AMOUNT 2
#define MAX_VALUE 10


std::vector<std::vector<int>> generateMatrix(const int rows, const int columns, const int maxValue = 10);
std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B);
void multiplyMatricesByBlocks(const std::vector<std::vector<int>>& matrixA, const std::vector<std::vector<int>>& matrixB, std::vector<std::vector<int>>& result, const int threadsAmount);
void thMultiplyMatrixBlock(const std::vector<std::vector<int>>& matrixA, const std::vector<std::vector<int>>& matrixB, std::vector<std::vector<int>>& result, std::vector<std::pair<int, int>> blockPositions);
void writeMatrixInFile(const std::string& filename, const std::vector<std::vector<int>>& result);
void printMatrix(const std::vector<std::vector<int>>& result);