#include "vector.h"

void
OpsVector::PrintVector(std::vector<int> &v) {
  for (int i = 0; i < (int) v.size(); i += 1) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
}

void
OpsVector::PrintVector(std::vector<double> &v) {
  for (int i = 0; i < (int) v.size(); i += 1) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
}

/**
 * @brief Add 1 to each element in the vector.
 *
 * @param v Vector to modify.
 * @return The modified vector.
 */
std::vector<int>
OpsVector::ModifyVector(std::vector<int> &v) {
  for (int i = 0; i < (int) v.size(); i += 1) {
    v.at(i) += 1;
  }
  return v;
}

/**
 * @brief Searches the vector for all instances of n.
 *
 * @param v Vector to search.
 * @param n Number to search for.
 * @return A vector of indices where n was found.
 */
#include <vector>
#include <algorithm>
#include <execution>

std::vector<int>
OpsVector::SearchVector(std::vector<int> &v, int n) {
  std::vector<int> ret;

  auto begin = v.begin();
  auto end = v.end();
  auto result = std::find(begin, end, n);
  while (result != end) {
    ret.push_back(std::distance(begin, result));
    result = std::find(std::next(result), end, n);
  }
  return ret;
}

/**
 * @brief Sorts the vector in ascending order.
 *
 * @param v Vector to sort.
 * @return The sorted vector.
 */
std::vector<int>
OpsVector::SortVector(std::vector<int> &v) {
  std::vector<int> ret(v);

  for (int i = 0; i < (int) ret.size(); i += 1) {
    for (int j = 0; j < (int) ret.size() - 1; j += 1) {
      if (ret[j] > ret[j + 1]) {
        int temp = ret[j];
        ret[j] = ret[j + 1];
        ret[j + 1] = temp;
      }
    }
  }
  return ret;
}

/**
 * @brief Reverses the vector.
 *
 * @param v Vector to reverse.
 * @return The reversed vector.
 */
#include <algorithm>
#include <vector>

std::vector<int> OpsVector::ReverseVector(std::vector<int> &v) {
  std::vector<int> ret(v.size());
  
  #pragma omp parallel for
  for (int i = 0; i < v.size(); ++i) {
    ret[i] = v[v.size() - 1 - i];
  }
  
  return ret;
}

/**
 * @brief Rotates the vector by n.
 *
 * @param v Vector to rotate.
 * @param n Number of elements to rotate by.
 * @return The rotated vector.
 */
std::vector<int>
OpsVector::RotateVector(std::vector<int> &v, int n) {
  std::vector<int> ret;

  for (int i = n; i < (int) v.size(); i += 1) {
    ret.push_back(v[i]);
  }
  for (int i = 0; i < n; i += 1) {
    ret.push_back(v[i]);
  }
  return ret;
}

/**
 * @brief Merges two vectors.
 *
 * @param v1 First vector.
 * @param v2 Second vector.
 * @return The merged vector.
 */
std::vector<int>
OpsVector::MergeVectors(std::vector<int> &v1, std::vector<int> &v2) {
  std::vector<int> ret;

  for (int i = 0; i < (int) v1.size(); i += 1) {
    ret.push_back(v1[i]);
  }
  for (int i = 0; i < (int) v2.size(); i += 1) {
    ret.push_back(v2[i]);
  }

  return ret;
}