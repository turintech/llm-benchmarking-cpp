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
DoubleForLoop::CountPairs(int n, int m) {
  // returns number of pairs from a randomly generated array of n numbers.
  // (each number is between 0 and m)
  // any number that appears twice is counted as a pair
  // any number that appears more than twice is NOT counted as a pair
  srand(0);
  int array[n];
  int count = 0;
  for (int i = 0; i < n; i += 1) {
    array[i] = rand() % m;
  }
  for (int i = 0; i < n; i += 1) {
    int nDuplicates = 0;
    for (int j = 0; j < n; j += 1) {
      if (array[i] == array[j]) {
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
DoubleForLoop::CountDuplicates(int n, int m) {
  // given two random sets of size n, (each number is between 0 and m)
  // returns the number of instances where the
  // values at the same index are equal
  srand(0);
  int array1[n];
  int array2[n];
  int count = 0;
  for (int i = 0; i < n; i += 1) {
    array1[i] = rand() % m;
    array2[i] = rand() % m;
  }
  for (int i = 0; i < n; i += 1) {
    for (int j = 0; j < n; j += 1) {
      if (i == j && array1[i] == array2[j]) {
        count += 1;
      }
    }
  }
  return count;
}

int
DoubleForLoop::SumMatrix(int n) {
  // given a 2D array of size n x n, returns the sum of all values in the array
  srand(0);
  int array[n][n];
  int sum = 0;
  for (int i = 0; i < n; i += 1) {
    for (int j = 0; j < n; j += 1) {
      array[i][j] = rand() % 100;
    }
  }
  for (int i = 0; i < n; i += 1) {
    for (int j = 0; j < n; j += 1) {
      sum += array[j][i];
    }
  }
  return sum;
}
