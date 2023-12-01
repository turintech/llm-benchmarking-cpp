#ifndef __DATASTRUCTURES_LINKEDLIST_H__
#define __DATASTRUCTURES_LINKEDLIST_H__

#include <random>

class LinkedList {
public:
  LinkedList(int n);
  void Print();
  void AddNode(int n);
  void SearchList(int n);
  void ReverseList();
};

#endif // __DATASTRUCTURES_LINKEDLIST_H__
