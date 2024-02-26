#include "strops.h"

std::string StrOps::ReverseString(std::string &s) { return std::string(s.rbegin(), s.rend()); }

bool
StrOps::IsPalindrome(const std::string &s) {

  if (s == std::string(s.rbegin(), s.rend())) {
    return true;
  }

  return false;
}