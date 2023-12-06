#ifndef __GENERATOR_GENARRAY_H__
#define __GENERATOR_GENARRAY_H__

#include <random>
#include <vector>

class GenArray {
public:
  GenArray();
  std::vector<int> RandomVector(int n, int m);
  std::vector<std::vector<int>> RandomSquareMatrix(int n, int m);
};

#endif   // __GENERATOR_GENARRAY_H__
