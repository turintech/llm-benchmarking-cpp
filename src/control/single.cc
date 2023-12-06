#include "single.h"

SingleForLoop::SingleForLoop() {}

int
SingleForLoop::SumRange(int n) {
  // sums all values from 0 to n
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

int
SingleForLoop::MaxArray(std::vector<int> arr) {
  // Returns the maximum value in an array of size n
  int max = 0;
  for (int i = 0; i < (int) arr.size(); i += 1) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

int
SingleForLoop::SumModulus(int n, int m) {
  // sums all values from 0 to n (non-inclusive) that are divisible by m
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
