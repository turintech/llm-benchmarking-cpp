#ifndef __GENERATOR_GENVECTOR_H__
#define __GENERATOR_GENVECTOR_H__

#include <vector>

namespace GenVector {

std::vector<int> RandomVector(int n, int m);
std::vector<double> RandomVectorDouble(int n, int l, int u);
std::vector<std::vector<int>> RandomSquareMatrix(int n, int m);
std::vector<std::vector<double>> RandomSquareMatrixDouble(int n, int l, int u);
std::vector<std::vector<double>> RandomMatrixDouble(int m, int n, int l, int u);

};   // namespace GenVector

#endif   // __GENERATOR_GENVECTOR_H__
