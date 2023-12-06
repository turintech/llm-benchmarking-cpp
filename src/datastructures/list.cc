#include "list.h"

std::list<int>
OpsList::Shuffle(std::list<int> &l) {
  std::list<int> ret;
  srand(0);

  while (l.size() > 0) {
    int r = rand() % l.size();
    std::_List_iterator<int> it = l.begin();
    std::advance(it, r);
    ret.push_back(*it);
    l.erase(it);
  }

  return l;
}
