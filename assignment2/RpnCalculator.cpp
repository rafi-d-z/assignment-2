//
// Created by csar on 7/3/22.
//

#include "RpnCalculator.hpp"
#include "Operator.hpp"
#include "fmt/format.h"
#include <stdexcept>
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
  // TODO: implement me
}

void RpnCalculator::Clear() { stack = Stack{}; }

} // namespace assignment2
