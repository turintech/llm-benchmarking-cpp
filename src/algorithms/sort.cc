#include "sort.h"

#include <algorithm>

/**
 * @brief Sorts a vector of integers (in place)
 *
 * @param v the vector to sort
 */
void
Sort::SortVector(std::vector<int> &v) {
  std::sort(v.begin(), v.end());
}

/**
 * @brief Partitions a vector of integers around a pivot
 *
 * @param v the vector to partition
 * @param pivot_value value of the pivot
 */
void
Sort::DutchFlagPartition(std::vector<int> &v, int pivot_value) {
  int next_value = 0;
  int size = v.size();

  for (int i = 0; i < size; ++i) {
    if (v[i] < pivot_value) {
      std::swap(v[i], v[next_value++]);
    }
  }

  for (int i = next_value; i < size; ++i) {
    if (v[i] == pivot_value) {
      std::swap(v[i], v[next_value++]);
    }
  }
}

/**
 * @brief Returns the largest n elements in a vector
 *
 * @param v the vector to search
 * @param n the number of elements to return
 * @return the largest n elements in the vector
 */
std::vector<int>
Sort::MaxN(std::vector<int> &v, int n) {
  std::vector<int> ret;
  std::vector<int> temp(v);

  std::partial_sort(temp.begin(), temp.begin() + n, temp.end(), std::greater<int>());

  ret.assign(temp.begin(), temp.begin() + n);

  return ret;
}