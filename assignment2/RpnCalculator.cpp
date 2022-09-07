#include "RpnCalculator.hpp"
#include "Operator.hpp"
#include "fmt/format.h"
#include <stdexcept>
#include <string>
#include <variant>

namespace assignment2 {
RpnCalculator::RpnCalculator() { stack = Stack{}; }

auto RpnCalculator::Value() -> double {
  // TODO: implement me
  throw std::runtime_error("Not implemented!");
}

void RpnCalculator::Push(std::variant<Operator, double> val) {
  // TODO: implement me
}

void RpnCalculator::Push(std::string c) {
  try {
    double d = std::stod(c);
    Push(d);
  } catch (std::invalid_argument const &ex) {
    // not a double, so it must be an operator
    if (c.length() == 1) {
      Operator op = parse(c.at(0));
      Push(op);
    } else {
      throw std::invalid_argument(
          fmt::format("{} cannot be parsed as a double or an operator", c));
    }
  }
}

void RpnCalculator::Clear() { stack = Stack{}; }

} // namespace assignment2
