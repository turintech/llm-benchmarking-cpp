#include <random>
#include "genvector.h"
#include <random>
#include <vector>

/** @brief Generates a random vector of length n
 *
 *  @param n Length of the vector to generate
 *  @param m Upper bound (non-inclusive) of the values in the vector
 *  @return A random vector of length n
 */
std::vector<int>
GenVector::RandomVector(int n, int m) {
  std::vector<int> ret(n);

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, m-1);

  for (int i = 0; i < n; i += 1) {
    ret[i] = dis(gen);
  }

  return ret;
}

/** @brief Generates a random vector of length n
 *
 *  @param n Length of the vector to generate
 *  @param l Lower bound (inclusive) of the values in the vector
 *  @param u Upper bound (non-inclusive) of the values in the vector
 *  @return A random vector of length n
 */
std::vector<double>
GenVector::RandomVectorDouble(int n, int l, int u) {
  std::vector<double> ret = std::vector<double>(n);

  std::mt19937 gen(0);
  std::uniform_real_distribution<double> dis(l, u);

  for (int i = 0; i < n; i += 1) {
    ret[i] = dis(gen);
  }

  return ret;
}

/** @brief Generates a random square matrix of size n
 *
 *  @param n Size of the matrix to generate
 *  @param m Upper bound (non-inclusive) of the values in the matrix
 *  @return A random square matrix of size n
 */
std::vector<std::vector<int>> GenVector::RandomSquareMatrix(int n, int m) {
  std::vector<std::vector<int>> ret(n, std::vector<int>(n));

  std::mt19937 gen(0);
  std::uniform_int_distribution<> dis(0, m-1);
  for (auto &row : ret) {
    for (auto &elem : row) {
      elem = dis(gen);
    }
  }

  return ret;
}