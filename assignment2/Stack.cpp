//
// Created by csar on 7/2/22.
//
#include "Stack.hpp"
#include "Node.hpp"
#include <fmt/ranges.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Node.hpp"

namespace assignment2 {

auto Stack::Size() -> int { return size_; }

Node* top;

void Stack::Push(Node* node) {
  // TODO: implement me
<<<<<<< HEAD

=======
  Node *temp;

  temp->data = node->data;
  temp->next = top;
  top = temp;
>>>>>>> 4fc3d02 (commit 12)
}

auto Stack::Pop() -> Node * {
  // TODO: implement me -- I throw an error
  Node *temp;

  temp = top;
  top = top->next;
  throw std::underflow_error("The stack is empty!");
<<<<<<< HEAD
=======
>>>>>>> 4fc3d02 (commit 12)
  free(temp);
}

Stack::~Stack() {
  // TODO: implement me; make sure to clean up the head pointer
<<<<<<< HEAD
  this->head = NULL; 
>>>>>>> 4fc3d02 (commit 12)
}

auto Stack::ToString() -> std::string {
  std::vector<std::string> elements;
  Node *node = head;
  while (node) {
    elements.push_back(node->ToString());
    node = node->next;
  }
  return fmt::format("{}", fmt::join(elements, " "));
}
} // namespace assignment2
