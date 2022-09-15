#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "Stack.hpp"
#include "Node.hpp"
#include "Operator.hpp"
#include "doctest/doctest.h"
#include <iostream>
#include <variant>

using namespace assignment2;

TEST_CASE("Test push then pop") {
  Node *node1 = new Node();
  node1->data = 1.0;
  Node *node2 = new Node();
  node2->data = 2.0;

  auto stack = Stack();
  stack.Push(node1);
  stack.Push(node2);
  auto top_data = stack.Pop();
  CHECK(top_data);
  CHECK(std::get<double>(top_data->data) == 2);
  auto bottom_data = stack.Pop();
  CHECK(std::get<double>(bottom_data->data) == 1);
}

TEST_CASE("Push then pop an Operator") {
  auto node = new Node();
  node->data = Operator::PLUS;

  auto stack = Stack();
  stack.Push(node);

  auto result = stack.Pop();
  CHECK(std::get<Operator>(result->data) == Operator::PLUS);
}

TEST_CASE("Test underflow exception") {
  auto stack = Stack();

  CHECK_THROWS(stack.Pop());
}
