#include "genvector.h"

/** @brief Generates a random vector of length n
 *
 *  @param n Length of the vector to generate
 *  @param m Upper bound (non-inclusive) of the values in the vector
 *  @return A random vector of length n
 */
 std::vector<int>
GenVector::RandomVector(int n, int m) {
  std::vector<int> ret(n);

  srand(0);
  for (int i = 0; i < n; i++) {
    ret[i] = rand() % m;
  }

  return ret;
}

/** @brief Generates a random square matrix of size n
 *
 *  @param n Size of the matrix to generate
 *  @param m Upper bound (non-inclusive) of the values in the matrix
 *  @return A random square matrix of size n
 */
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