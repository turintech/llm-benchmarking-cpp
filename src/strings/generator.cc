#include "generator.h"

Generator::Generator() {}

std::string
Generator::RandomString(int n) {
  std::string ret;

  srand(0);
  for (int i = 0; i < n; i += 1) {
    ret += (char) (rand() % 26 + 97);
  }
  return ret;
}
