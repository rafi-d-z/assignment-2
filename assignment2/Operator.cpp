//
// Created by csar on 7/2/22.
//

#include "Operator.hpp"
#include <unordered_map>
#include <stdexcept>
#include <string>
#include <fmt/core.h>

namespace assignment2 {
    static std::unordered_map<char, Operator> const lookup_table = {
            {'+', Operator::PLUS},
            {'-', Operator::MINUS},
            {'*', Operator::TIMES},
            {'/', Operator::DIVIDE}};

    auto parseChar(char c) -> Operator {
        if (auto it = lookup_table.find(c); it != lookup_table.end()) {
            return it->second;
        } else {
            throw std::invalid_argument(fmt::format("Could not parse {} as an operator", std::string(1, c)));
        }
    }
} // namespace assignment2