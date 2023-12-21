#include "strops.h"

 std::string
StrOps::ReverseString(std::string &s) {
  std::string ret;

  for (std::string::reverse_iterator rit = s.rbegin(); rit != s.rend(); ++rit) {
    ret += *rit;
  }
  return ret;
}

bool
StrOps::IsPalindrome(const std::string &s) {

  if (s == std::string(s.rbegin(), s.rend())) {
    return true;
  }

  return false;
}