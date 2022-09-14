#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "RpnCalculator.hpp"
#include "doctest/doctest.h"
#include <array>
#include <string>

using namespace assignment2;

TEST_CASE("2 + 2 = 4") {
  auto calculator = RpnCalculator();
  calculator.Push("2");
  calculator.Push("2");
  calculator.Push("+");
  CHECK(calculator.Value() == 4.0);
}

TEST_CASE("5-2=3") {
  RpnCalculator calculator = RpnCalculator{};
  calculator.Push("5");
  calculator.Push("2");
  calculator.Push("-");
  CHECK(calculator.Value() == 3.0);
}

// Some examples from https://www.eolymp.com/en/problems/5060
TEST_CASE("2 * (4 + 8) = 24") {
  auto calculator = RpnCalculator();
  std::array<std::string, 5> entries = {"2", "4", "8", "+", "*"};
  for (const std::string &item : entries) {
    calculator.Push(item);
  }
  CHECK(calculator.Value() == 24.0);
}

TEST_CASE("((2*5) + 4) / (3*2) + 1) = 2 ") {
  auto calculator = RpnCalculator();
  std::array<std::string,11> arr = {"2", "5", "*", "4", "+", "3", "2",
                                           "*", "1", "+", "/"};
  for (const std::string &item : arr) {
    calculator.Push(item);
  }
  CHECK(calculator.Value() == 2.0);
}

TEST_CASE("Value throws exception for the empty stack") {
  auto calculator = RpnCalculator();
  CHECK_THROWS(calculator.Value());
}
