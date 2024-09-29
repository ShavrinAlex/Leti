#pragma once
#include <iostream>
#include <fstream>
#include <random>
#include <vector>


void setDefaultMatricesParams(int& rowsA, int& columnsA, int& rowsB, int& columnsB, int& maxValue);
std::vector<std::vector<int>> generateMatrix(const int rows, const int columns, const int maxValue = 10);
std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B);
void writeMatrixInFile(const std::string& filename, const std::vector<std::vector<int>>& result);
void printMatrix(const std::vector<std::vector<int>>& result);