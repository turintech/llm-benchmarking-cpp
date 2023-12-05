#include "linkedlist.h"

LinkedList::LinkedList(int n) {
  srand(0);

  head = new Node;
  head->data = rand() % 100;
  head->next = nullptr;

  Node *current = head;
  for (int i = 1; i < n; ++i) {
    Node *new_node = new Node;
    new_node->data = rand() % 100;
    new_node->next = nullptr;
    current->next = new_node;
    current = new_node;
  }
}

void LinkedList::Print() {
  Node *current = head;
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

void LinkedList::AddNode(int n) {
  Node *current = head;
  while (current->next != nullptr) {
    current = current->next;
  }

  Node *new_node = new Node;
  new_node->data = n;
  new_node->next = nullptr;
  current->next = new_node;
}

bool LinkedList::SearchList(int n) {
  Node *current = head;
  while (current != nullptr) {
    if (current->data == n) {
      return true;
    }
    current = current->next;
  }
  return false;
}

void LinkedList::ReverseList() {
  Node *current = head;
  Node *prev = nullptr;
  Node *next = nullptr;

  while (current != nullptr) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  head = prev;
}
