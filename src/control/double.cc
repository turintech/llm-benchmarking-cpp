#include "double.h"

DoubleForLoop::DoubleForLoop() {}

long
DoubleForLoop::SumSquare(int n) {
  // sums all values squared from 0 to n
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

long
DoubleForLoop::SumTriangle(int n) {
  // returns sum of triangle numbers from T(1) to T(n)
  long sum = 0;
  for (int i = 0; i < n + 1; i += 1) {
    for (int j = 0; j < i; j += 1) {
      sum = sum + (long) j;
    }
  }
  return sum;
}

int
DoubleForLoop::CountPairs(std::vector<int> arr) {
  // returns number of pairs from a vector of size n
  // (each number is between 0 and m)
  // any number that appears twice is counted as a pair
  // any number that appears more than twice is NOT counted as a pair
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

int
DoubleForLoop::CountDuplicates(std::vector<int> arr0, std::vector<int> arr1) {
  // given two arrays of size n,
  // returns the number of instances where the
  // values at the same index are equal
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

int
DoubleForLoop::SumMatrix(std::vector<std::vector<int>> matrix) {
  // given a 2D array of size n x n, returns the sum of all values in the array
  int n = (int) matrix.size();
  int sum = 0;
  for (int i = 0; i < n; i += 1) {
    for (int j = 0; j < n; j += 1) {
      sum += matrix[j][i];
    }
  }
  return sum;
}
