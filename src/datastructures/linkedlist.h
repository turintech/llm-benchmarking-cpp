#ifndef __DATASTRUCTURES_LINKEDLIST_H__
#define __DATASTRUCTURES_LINKEDLIST_H__

#include <iostream>
#include <random>

struct Node {
  int data;
  Node *next;
};

class LinkedList {
public:
  LinkedList(int n);
  void Print();
  void AddNode(int n);
  bool SearchList(int n);
  void ReverseList();

private:
  Node *head;
};

#endif // __DATASTRUCTURES_LINKEDLIST_H__
