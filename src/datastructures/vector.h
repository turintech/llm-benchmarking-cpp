#ifndef __DATASTRUCTURES_VECTOR_H__
#define __DATASTRUCTURES_VECTOR_H__

#include <random>
#include <vector>

class Vector {
public:
  Vector();
  std::vector<int> RandomVector(int n);
  std::vector<int> ModifyVector(std::vector<int> &v);
  std::vector<int> SearchVector(std::vector<int> &v, int n);
  std::vector<int> SortVector(std::vector<int> &v);
  std::vector<int> ReverseVector(std::vector<int> &v);
  std::vector<int> RotateVector(std::vector<int> &v, int n);
  std::vector<int> MergeVectors(std::vector<int> &v1, std::vector<int> &v2);
};

#endif // __DATASTRUCTURES_VECTOR_H__
