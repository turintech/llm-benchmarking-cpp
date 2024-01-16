#ifndef __GENERATOR_GENVECTOR_H__
#define __GENERATOR_GENVECTOR_H__

#include <random>
#include <vector>

namespace GenVector {

std::vector<int> RandomVector(int n, int m);
std::vector<double> RandomVectorDouble(int n, int l, int u);
std::vector<std::vector<int>> RandomSquareMatrix(int n, int m);

};   // namespace GenVector

#endif   // __GENERATOR_GENVECTOR_H__
