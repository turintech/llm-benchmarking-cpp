#ifndef __DATASTRUCTURES_VECTOR_H__
#define __DATASTRUCTURES_VECTOR_H__

#include <vector>

namespace OpsVector {

void PrintVector(const std::vector<int> &v);
void PrintVector(const std::vector<double> &v);
void PrintMatrix(const std::vector<std::vector<double>> &m);
std::vector<int> ModifyVector(std::vector<int> &v);
std::vector<int> SearchVector(std::vector<int> &v, int n);
std::vector<int> SortVector(std::vector<int> &v);
std::vector<int> ReverseVector(std::vector<int> &v);
std::vector<int> RotateVector(std::vector<int> &v, int n);
std::vector<int> MergeVectors(std::vector<int> &v1, std::vector<int> &v2);

};   // namespace OpsVector

#endif   // __DATASTRUCTURES_VECTOR_H__
