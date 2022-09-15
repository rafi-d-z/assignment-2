//
// Created by csar on 7/2/22.
//
#include "Stack.hpp"
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
  Node* temp = new Node();

  temp->data = data;
  temp->next = top;
  top = temp;

}

auto Stack::Pop() -> Node * {
  // TODO: implement me -- I throw an error
  throw std::underflow_error("The stack is empty!");

  Node* temp;

  temp = top;
  top = top->link;
  free(temp);
}

Stack::~Stack() {
  // TODO: implement me; make sure to clean up the head pointer
  
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
