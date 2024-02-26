#include <unordered_map>
#include "double.h"

/**
 * @brief Sums all values squared from 0 to n
 *
 * @param n
 * @return the sum of all values squared from 0 to n
 */
long
DoubleForLoop::SumSquare(int n) {
  long sum = 0;
  for (int i = 0; i < n; i += 1) {
    for (int j = 0; j < n; j += 1) {
      if (i == j) {
        sum = sum + (long) (i * j);
      }
    }
  }
  return sum;
}

/**
 * @brief Sums all triangle numbers from T(1) to T(n)
 *
 * @param n
 * @return the sum of all triangle numbers from T(1) to T(n)
 */
long
DoubleForLoop::SumTriangle(int n) {
  long sum = 0;
  for (int i = 0; i < n + 1; i += 1) {
    for (int j = 0; j < i; j += 1) {
      sum = sum + (long) j;
    }
  }
  return sum;
}

/**
 * @brief Counts the number of pairs in an vay
 *
 * Pairs are defined as exactly two instances of the same value in
 * the vay.
 *
 * @param v
 * @return the number of pairs in an vay
 */
int DoubleForLoop::CountPairs(std::vector<int> v) {
  std::unordered_map<int, int> numCount;
  for (const auto& num : v) {
    numCount[num]++;
  }
  int count = 0;
  for (const auto& pair : numCount) {
    if (pair.second == 2) {
      count++;
    }
  }
  return count;
}

/**
 * @brief Counts the number of instances where the values at the same index are equal
 *
 * @param v0
 * @param v1
 * @return the number of instances where the values at the same index are equal
 */
int
DoubleForLoop::CountDuplicates(std::vector<int> v0, std::vector<int> v1) {
  int count = 0;
  for (int i = 0; i < (int) v0.size(); i += 1) {
    for (int j = 0; j < (int) v1.size(); j += 1) {
      if (i == j && v0[i] == v1[j]) {
        count += 1;
      }
    }
  }
  return count;
}

/**
 * @brief Sums all values in a 2D vay
 *
 * @param matrix
 * @return the sum of all values in a 2D vay
 */
int
DoubleForLoop::SumMatrix(std::vector<std::vector<int>> matrix) {
  int n = (int) matrix.size();
  int sum = 0;
  for (int i = 0; i < n; i += 1) {
    for (int j = 0; j < n; j += 1) {
      sum += matrix[j][i];
    }
  }
  return sum;
}