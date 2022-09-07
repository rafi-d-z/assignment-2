#ifndef ASSIGNMENT_2_RPNCALCULATOR_HPP
#define ASSIGNMENT_2_RPNCALCULATOR_HPP

#include "Operator.hpp"
#include "Stack.hpp"
#include <string>
#include <variant>

namespace assignment2 {

class RpnCalculator {
private:
  Stack stack;

public:
  RpnCalculator();
  auto Value() -> double;
  void Push(std::variant<Operator, double>);
  void Push(std::string c);
  void Clear();
};

} // namespace assignment2

#endif // ASSIGNMENT_2_RPNCALCULATOR_HPP
