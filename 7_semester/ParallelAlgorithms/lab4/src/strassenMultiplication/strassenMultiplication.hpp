#pragma once
#include <vector>
#include <ctpl_stl.h>


std::vector<int> multiplyMatricesByStrassen(const std::vector<int>& A, const std::vector<int>& B, const int size, ctpl::thread_pool* threadPool = nullptr);
void splitMatrix(const std::vector<int>& A, std::vector<int>& A11, std::vector<int>& A12, std::vector<int>& A21, std::vector<int>& A22, const int size);
std::vector<int> concatMatrices(const std::vector<int>& C11, const std::vector<int>& C12, const std::vector<int>& C21, const std::vector<int>& C22, const int resultSize);
// void diversificationTasksByThreads(
//     const int numThreads, 
//     std::vector<int>& D, std::vector<int>& D1, 
//     std::vector<int>& D2, std::vector<int>& H1, 
//     std::vector<int>& H2, std::vector<int>& V1, 
//     std::vector<int>& V2,
//     const std::vector<int>& A11, const std::vector<int>& A12, 
//     const std::vector<int>& A21, const std::vector<int>& A22,
//     const std::vector<int>& B11, const std::vector<int>& B12, 
//     const std::vector<int>& B21, const std::vector<int>& B22,
//     const int size
// );