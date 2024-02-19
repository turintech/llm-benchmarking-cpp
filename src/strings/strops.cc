#include "strops.h"

#include <algorithm>
#include <string>

std::string StrOps::ReverseString(std::string &s) {
  std::string ret = s;
  std::reverse(ret.begin(), ret.end());
  return ret;
}

bool
StrOps::IsPalindrome(const std::string &s) {

  if (s == std::string(s.rbegin(), s.rend())) {
    return true;
  }

  return false;
}