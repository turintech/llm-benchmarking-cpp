#ifndef CONTROL_DOUBLE_H_
#define CONTROL_DOUBLE_H_

#include <vector>

class DoubleForLoop {
public:
  DoubleForLoop();
  long SumSquare(int n);
  long SumTriangle(int n);
  int CountPairs(std::vector<int> arr);
  int CountDuplicates(std::vector<int> arr0, std::vector<int> arr1);
  int SumMatrix(std::vector<std::vector<int>> matrix);
};

#endif   // CONTROL_DOUBLE_H_
