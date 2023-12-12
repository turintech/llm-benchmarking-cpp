#ifndef __ALGORITHMS_SORT_H__
#define __ALGORITHMS_SORT_H__

#include <vector>

namespace Sort {
void SortVector(std::vector<int> &arr);
std::vector<int> DutchFlagPartition(std::vector<int> &arr, int pivot_value = 0);
std::vector<int> MaxN(std::vector<int> &arr, int n);

};   // namespace Sort

#endif   // __ALGORITHMS_SORT_H__
