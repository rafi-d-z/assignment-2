#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "Node.hpp"
#include "Operator.hpp"
#include "doctest/doctest.h"
#include <cstddef>
#include <vector>

using namespace assignment2;

TEST_CASE("A Node starts with an empty pointer") {
  SUBCASE("When its value is a double") {
    Node node = Node();
    node.data = 1.1;

    CHECK(node.next == nullptr);
  }

  SUBCASE("When its value is an operator") {
    Node node = Node();
    node.data = Operator::DIVIDE;

    CHECK(node.next == nullptr);
  }
}

TEST_CASE("Nodes make a linked list") {
  Node node1 = Node();
  Node node2 = Node();

  node1.data = 1.0;
  node2.data = Operator::MINUS;

  node1.next = &node2;

  std::vector<std::variant<Operator, double>> elements = {};

  Node *node = &node1;

  // not the safest, but we do know that node isn't nullptr
  do {
    elements.push_back(node->data);
    node = node->next;
  } while (node != nullptr);

  std::vector<std::variant<Operator, double>> expected = {1.0, Operator::MINUS};

  CHECK(elements.size() == 2);
  CHECK(elements == expected);
}

TEST_CASE("Check the variant type") {
  SUBCASE("When it's a double") {
    Node node = Node();
    node.data = 2.0;

    CHECK(node.data.index() == 1); // double is the second type
  }

  SUBCASE("When it's an operator") {
    Node node = Node();
    node.data = Operator::DIVIDE;

    CHECK(node.data.index() == 0); // Operator is the first type
  }
}