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
 * @brief Counts the number of pairs in an array
 *
 * Pairs are defined as exactly two instances of the same value in
 * the array.
 *
 * @param arr
 * @return the number of pairs in an array
 */
int
DoubleForLoop::CountPairs(std::vector<int> arr) {
  int count = 0;
  for (int i = 0; i < (int) arr.size(); i += 1) {
    int nDuplicates = 0;
    for (int j = 0; j < (int) arr.size(); j += 1) {
      if (arr[i] == arr[j]) {
        nDuplicates += 1;
      }
    }
    if (nDuplicates == 2) {
      count += 1;
    }
  }
  return count / 2;
}

/**
 * @brief Counts the number of instances where the values at the same index are equal
 *
 * @param arr0
 * @param arr1
 * @return the number of instances where the values at the same index are equal
 */
int
DoubleForLoop::CountDuplicates(std::vector<int> arr0, std::vector<int> arr1) {
  int count = 0;
  for (int i = 0; i < (int) arr0.size(); i += 1) {
    for (int j = 0; j < (int) arr1.size(); j += 1) {
      if (i == j && arr0[i] == arr1[j]) {
        count += 1;
      }
    }
  }
  return count;
}

/**
 * @brief Sums all values in a 2D array
 *
 * @param matrix
 * @return the sum of all values in a 2D array
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
