#include "reverse.h"

Reverse::Reverse() {}

std::string
Reverse::ReverseString(std::string &s) {
  std::string ret;

  for (std::string::reverse_iterator rit = s.rbegin(); rit != s.rend(); ++rit) {
    ret.insert(ret.end(), *rit);
  }
  return ret;
}
