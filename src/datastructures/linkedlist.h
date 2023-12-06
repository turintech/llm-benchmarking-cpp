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
  ~LinkedList();
  static LinkedList *RandomLinkedList(int n, int m);
  void Print();
  void AddNode(int n);
  bool SearchList(int n);
  void ReverseList();
  int At(int n);

private:
  Node *head;
};

#endif   // __DATASTRUCTURES_LINKEDLIST_H__
