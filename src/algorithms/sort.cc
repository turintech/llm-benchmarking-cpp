#include "sort.h"

#include <algorithm>

/**
 * @brief Sorts a vector of integers
 *
 * @param arr the vector to sort
 * @return the sorted vector
 */
std::vector<int>
Sort::SortVector(std::vector<int> &arr) {
  std::sort(arr.begin(), arr.end());
  return arr;
}

/**
 * @brief Partitions a vector of integers around a pivot
 *
 * @param arr the vector to partition
 * @param pivot_value value of the pivot
 * @return the partitioned vector
 */
std::vector<int>
Sort::DutchFlagPartition(std::vector<int> &arr, int pivot_value) {
  int next_value = 0;

  for (int i = 0; i < (int) arr.size(); i += 1) {
    if (arr[i] < pivot_value) {
      std::swap(arr[i], arr[next_value]);
      next_value += 1;
    }
  }

  for (int i = next_value; i < (int) arr.size(); i += 1) {
    if (arr[i] == pivot_value) {
      std::swap(arr[i], arr[next_value]);
      next_value += 1;
    }
  }

  return arr;
}

/**
 * @brief Returns the largest n elements in a vector
 *
 * @param arr the vector to search
 * @param n the number of elements to return
 * @return the largest n elements in the vector
 */
std::vector<int>
Sort::MaxN(std::vector<int> &arr, int n) {
  std::vector<int> ret;

  std::partial_sort(arr.begin(), arr.begin() + n, arr.end(), std::greater<int>());

  ret.assign(arr.begin(), arr.begin() + n);

  return ret;
}