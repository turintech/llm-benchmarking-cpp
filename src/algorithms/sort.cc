#include <algorithm>
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
  int smaller = 0, equal = 0, larger = v.size();

  while (equal < larger) {
    if (v[equal] < pivot_value) {
      std::swap(v[smaller++], v[equal++]);
    } else if (v[equal] == pivot_value) {
      ++equal;
    } else {
      std::swap(v[equal], v[--larger]);
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
  // So that we don't modify the original vector
  std::vector<int> temp(v);

  std::partial_sort(temp.begin(), temp.begin() + n, temp.end(), std::greater<int>());

  ret.assign(temp.begin(), temp.begin() + n);

  return ret;
}