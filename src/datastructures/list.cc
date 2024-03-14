#include "list.h"

/** @brief shuffles a list into a new list
 *
 * @param l the list to shuffle
 * @return a new list with the elements of l shuffled
 */
std::list<int>
OpsList::Shuffle(std::list<int> &l) {
  std::list<int> tmp = l;
  std::list<int> ret;
  srand(0);

  while (!tmp.empty()) {
    int r = rand() % tmp.size();
    std::list<int>::iterator it = tmp.begin();
    std::advance(it, r);
    ret.push_back(*it);
    tmp.erase(it);
  }

  return ret;
}

/** @brief slices a list into a new list
 *
 * @param l the list to slice
 * @param start the start index of the slice
 * @param end the end index of the slice (exclusive)
 * @return a new list with the elements of l sliced
 */
std::list<int> OpsList::Slice(std::list<int> &l, int start, int end) {
  std::list<int> ret;
  auto it = l.begin();
  std::advance(it, start);
  for (int i = start; i < end && it != l.end(); i++) {
    ret.push_back(*it++);
  }
  return ret;
}