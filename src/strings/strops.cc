#include "strops.h"

std::string
StrOps::ReverseString(std::string &s) {
  return {s.crbegin(), s.crend()};
}

bool
StrOps::IsPalindrome(const std::string &s) {

  if (s == std::string(s.rbegin(), s.rend())) {
    return true;
  }

  return false;
}