#include "palindrome.h"

Palindrome::Palindrome() {}

bool
Palindrome::IsPalindrome(const std::string &s) {

  if (s == std::string(s.rbegin(), s.rend())) {
    return true;
  }

  return false;
}
