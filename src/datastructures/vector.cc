#include "vector.h"

Vector::Vector() {}

void
Vector::PrintVector(std::vector<int> &v) {
  for (int i = 0; i < (int) v.size(); i += 1) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
}

std::vector<int>
Vector::RandomVector(int n) {
  std::vector<int> v;
  srand(0);

  for (int i = 0; i < n; i += 1) {
    v.push_back(rand() % 100);
  }
  return v;
}

std::vector<int>
Vector::ModifyVector(std::vector<int> &v) {
  for (int i = 0; i < (int) v.size(); i += 1) {
    v.at(i) += 1;
  }
  return v;
}

std::vector<int>
Vector::SearchVector(std::vector<int> &v, int n) {
  std::vector<int> ret;

  for (int i = 0; i < (int) v.size(); i += 1) {
    if (v[i] == n) {
      ret.push_back(i);
    }
  }
  return ret;
}

std::vector<int>
Vector::SortVector(std::vector<int> &v) {
  std::vector<int> ret = v;

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

std::vector<int>
Vector::ReverseVector(std::vector<int> &v) {
  std::vector<int> ret;

  for (int i = (int) v.size() - 1; i >= 0; i -= 1) {
    ret.push_back(v[i]);
  }
  return ret;
}

std::vector<int>
Vector::RotateVector(std::vector<int> &v, int n) {
  std::vector<int> ret;

  for (int i = n; i < (int) v.size(); i += 1) {
    ret.push_back(v[i]);
  }
  for (int i = 0; i < n; i += 1) {
    ret.push_back(v[i]);
  }
  return ret;
}

std::vector<int>
Vector::MergeVectors(std::vector<int> &v1, std::vector<int> &v2) {
  std::vector<int> ret;

  for (int i = 0; i < (int) v1.size(); i += 1) {
    ret.push_back(v1[i]);
  }
  for (int i = 0; i < (int) v2.size(); i += 1) {
    ret.push_back(v2[i]);
  }

  return ret;
}
