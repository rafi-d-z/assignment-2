//
// Created by csar on 7/2/22.
//

#include "Operator.hpp"
#include <fmt/core.h>
#include <stdexcept>
#include <string>
#include <unordered_map>

namespace assignment2 {
    static std::unordered_map<char, Operator> const lookup_table = {
            {'+', Operator::PLUS},
            {'-', Operator::MINUS},
            {'*', Operator::TIMES},
            {'/', Operator::DIVIDE}};

    static std::unordered_map<Operator, char> const reverse_lookup = {
        {Operator::PLUS, '+'},
        {Operator::MINUS, '-'},
        {Operator::TIMES, '*'},
        {Operator::DIVIDE, '/'}
    };

    auto rep(Operator o) -> std::string {
        if (auto it = reverse_lookup.find(o); it != reverse_lookup.end()) {
            return {it->second};
        } else {
            throw std::logic_error(fmt::format("No representation for {}", o));
        }
    }

auto parse(char c) -> Operator {
  if (auto it = lookup_table.find(c); it != lookup_table.end()) {
    return it->second;
  } else {
    throw std::invalid_argument(
        fmt::format("Could not parse {} as an operator", std::string(1, c)));
  }
}
} // namespace assignment2