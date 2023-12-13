#ifndef __DATASTRUCTURES_VECTOR_H__
#define __DATASTRUCTURES_VECTOR_H__

#include <list>
#include <random>

namespace OpsList {

std::list<int> Shuffle(std::list<int> &l);
std::list<int> Slice(std::list<int> &l, int start, int end);

};   // namespace OpsList

#endif   // __DATASTRUCTURES_VECTOR_H__
