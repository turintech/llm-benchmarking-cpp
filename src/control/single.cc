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
SingleForLoop::MaxRandom(int n) {
  // samples n random numbers and returns the max
  srand(0);
  int array[n];
  int max = 0;
  for (int i = 0; i < n; i += 1) {
    array[i] = rand() % 100;
  }
  for (int i = 0; i < n; i += 1) {
    if (array[i] > max) {
      max = array[i];
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
