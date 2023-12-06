#ifndef __GENERATOR_GENARRAY_H__
#define __GENERATOR_GENARRAY_H__

#include <random>
#include <vector>

namespace GenVector {

std::vector<int> RandomVector(int n, int m);
std::vector<std::vector<int>> RandomSquareMatrix(int n, int m);

};   // namespace GenVector

#endif   // __GENERATOR_GENARRAY_H__
