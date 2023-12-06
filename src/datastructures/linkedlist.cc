#include "linkedlist.h"

/** @brief Constructor for LinkedList class
 *
 * @param n Data to add to the head node
 */
LinkedList::LinkedList(int n) {
  head = new Node;
  head->data = n;
  head->next = nullptr;
}

/** @brief Destructor for LinkedList class
 *
 */
LinkedList::~LinkedList() {
  Node *current = head;
  Node *next = nullptr;

  while (current != nullptr) {
    next = current->next;
    delete current;
    current = next;
  }
}

/** @brief Generates a random linked list of length n
 *
 *  @param n Length of the linked list to generate
 *  @param m Upper bound (non-inclusive) of the values in the linked list
 *  @return A random linked list of length n
 */
LinkedList *
LinkedList::RandomLinkedList(int n, int m) {
  LinkedList *ret = new LinkedList(rand() % m);

  srand(0);
  for (int i = 0; i < n - 1; i += 1) {
    ret->AddNode(rand() % m);
  }

  return ret;
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

/** @brief Returns the data at the nth node
 *
 *  @param n Index of the node to return
 *  @return Data at the nth node
 */
int
LinkedList::At(int n) {
  Node *current = head;
  for (int i = 0; i < n; i += 1) {
    current = current->next;
  }
  return current->data;
}
