#include "single.h"

/**
 * @brief Sums all integer values from 0 to n
 *
 * @param n the upper bound (non-inclusive)
 * @return the sum of all integer values from 0 to n
 */
int
SingleForLoop::SumRange(int n) {
  int array[n];
  int sum = 0;
  for (int i = 0; i < n; i += 1) {
    array[i] = i;
  }
  for (int i = 0; i < n; i += 1) {
    sum += array[i];
  }
  return sum;
}

/**
 * @brief Returns the maximum value in an array of size n
 *
 * @param arr the array to search
 * @return the maximum value in the array
 */
int
SingleForLoop::MaxVector(std::vector<int> &arr) {
  // Returns the maximum value in an array of size n
  int max = 0;
  for (int i = 0; i < (int) arr.size(); i += 1) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

/**
 * @brief Sums all values from 0 to n that are divisible by m
 *
 * @param n the upper bound (non-inclusive)
 * @param m the modulus
 * @return the sum of all values from 0 to n that are divisible by m
 */
int
SingleForLoop::SumModulus(int n, int m) {
  int array[n];
  int sum = 0;
  for (int i = 0; i < n; i += 1) {
    array[i] = i;
  }
  for (int i = 0; i < n; i += 1) {
    if (array[i] % m == 0) {
      sum += array[i];
    }
  }
  return sum;
}
