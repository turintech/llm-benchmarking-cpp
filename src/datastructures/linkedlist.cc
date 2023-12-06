#include "linkedlist.h"

/** @brief Constructor for LinkedList class
 *
 *  @param n Number of nodes in the linked list
 */
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

/** @brief Prints the linked list
 *
 */
void
LinkedList::Print() {
  Node *current = head;
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

/** @brief Adds a node to the end of the linked list
 *
 *  @param n Data to add to the new node
 */
void
LinkedList::AddNode(int n) {
  Node *current = head;
  while (current->next != nullptr) {
    current = current->next;
  }

  Node *new_node = new Node;
  new_node->data = n;
  new_node->next = nullptr;
  current->next = new_node;
}

/** @brief Searches the linked list for a node with the given data
 *
 *  @param n Data to search for
 *  @return True if the data is found, false otherwise
 */
bool
LinkedList::SearchList(int n) {
  Node *current = head;
  while (current != nullptr) {
    if (current->data == n) {
      return true;
    }
    current = current->next;
  }
  return false;
}

/** @brief Reverses the linked list
 *
 */
void
LinkedList::ReverseList() {
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
