#ifndef ASSIGNMENT_2_NODE_H
#define ASSIGNMENT_2_NODE_H

#include "Operator.hpp"
#include <fmt/core.h>
#include <iostream>
#include <variant>

namespace assignment2 {

// An element of a linked list. It contains data that can be one of two types:
// - a double
// - an Operator
struct Node {
  std::variant<Operator, double> data;
  Node *next = nullptr;

  auto ToString() -> std::string {
    if (data.index() == 0) {
      return rep(std::get<Operator>(data));
    } else {
      return fmt::format("{:f}", std::get<double>(data));
    }
  }
};
} // namespace assignment2
#endif // ASSIGNMENT_2_NODE_H
