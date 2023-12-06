#ifndef STRINGS_STROPS_H_
#define STRINGS_STROPS_H_

#include <string>

class StrOps {
public:
  StrOps();
  bool IsPalindrome(const std::string &s);
  std::string ReverseString(std::string &s);
};

#endif   // STRINGS_STROPS_H_
