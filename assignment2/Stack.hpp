/**
 * Header file for the Stack class.
 */
#ifndef ASSIGNMENT_2_LINKEDLIST_HPP
#define ASSIGNMENT_2_LINKEDLIST_HPP

#include "Node.hpp"

namespace assignment2 {
/* A class implementing a Stack backed by a linked list of Nodes */
class Stack {
private:
  // Pointer to the head of the linked list.
  Node *head;

  // the number of elements on the stack
  int size_{0};

public:
  Stack() = default;
  ~Stack();

  /**
   * Get the number of elements on the stack.
   */
  auto Size() -> int;

  /**
   * Push an element onto the stack.
   */
  void Push(Node *node);

  /**
   * Pop the top element off the stack.
   */
  auto Pop() -> Node *;

  /**
   * String representation of the stack
   * The bottom of the stack appears first
   */
  auto ToString() -> std::string;
};
} // namespace assignment2
#endif // ASSIGNMENT_2_LINKEDLIST_HPP
