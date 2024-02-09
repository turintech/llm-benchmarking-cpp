#include "single.h"

/**
 * @brief Sums all integer values from 0 to n
 *
 * @param n the upper bound (non-inclusive)
 * @return the sum of all integer values from 0 to n
 */
int
SingleForLoop::SumRange(int n) {
  int sum = 0;
  for (int i = 0; i < n; i += 1) {
    sum += i;
  }
  return sum;
}

/**
 * @brief Returns the maximum value in an array of size n
 *
 * @param arr the array to search
 * @return the maximum value in the array
 *
 * @todo Make a function that doesn't pass by reference
 * a code optimiser would probably try to update the input
 * which will make the unit tests fail, so we need a way
 * to make sure that doesn't happen
 */
int
SingleForLoop::MaxVector(std::vector<int> &arr) {
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
  int sum = 0;
  for (int i = 0; i < n; i += 1) {
    if (i % m == 0) {
      sum += i;
    }
  }
  return sum;
}