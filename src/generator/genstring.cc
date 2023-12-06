#include "genstring.h"

/** @brief Generates a random string of length n
 *
 *  @param n Length of the string to generate
 *  @return A random string of length n
 */
std::string
GenString::RandomString(int n) {
  std::string ret;

  srand(0);
  for (int i = 0; i < n; i += 1) {
    ret += (char) (rand() % 26 + 97);
  }
  return ret;
}
