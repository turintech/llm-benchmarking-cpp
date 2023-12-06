#include "genvector.h"

std::vector<int>
GenVector::RandomVector(int n, int m) {
  std::vector<int> ret = std::vector<int>(n);

  srand(0);
  for (int i = 0; i < n; i += 1) {
    ret[i] = rand() % m;
  }

  return ret;
}

std::vector<std::vector<int>>
GenVector::RandomSquareMatrix(int n, int m) {
  std::vector<std::vector<int>> ret = std::vector<std::vector<int>>(n);

  srand(0);
  for (int i = 0; i < n; i += 1) {
    ret[i] = std::vector<int>(n);
    for (int j = 0; j < n; j += 1) {
      ret[i][j] = rand() % m;
    }
  }

  return ret;
}
