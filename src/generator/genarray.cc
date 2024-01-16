#include "genarray.h"

double *
GenArray::RandomArray(int n, int m) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0, m);
  double *arr = new double[n];
  for (int i = 0; i < n; i++) {
    arr[i] = dis(gen);
  }
  return arr;
}

double *
GenArray::ZeroArray(int n) {
  double *arr = new double[n];
  for (int i = 0; i < n; i++) {
    arr[i] = 0;
  }
  return arr;
}