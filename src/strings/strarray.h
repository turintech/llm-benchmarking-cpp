#ifndef STRINGS_STRARRAY_H_
#define STRINGS_STRARRAY_H_

#include <string>
#include <vector>

class StrArray {
public:
  StrArray();
  void SwapAdjacent(std::vector<std::string> &v);
};

#endif   // STRINGS_STRARRAY_H_