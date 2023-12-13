#include "genlist.h"

#include <cstdlib>

/** @brief Generates a random list of length n
 *
 *  @param n Length of the list to generate
 *  @param m Upper bound (non-inclusive) of the values in the list
 *  @return A random list of length n
 */
std::list<int>
GenList::RandomList(int n, int m) {
  std::list<int> ret = std::list<int>(n);

  srand(0);
  for (int i = 0; i < n; i += 1) {
    ret.push_back(rand() % m);
  }

  return ret;
}
