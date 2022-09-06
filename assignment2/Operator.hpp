//

#ifndef ASSIGNMENT_2_OPERATOR_HPP
#define ASSIGNMENT_2_OPERATOR_HPP

#include <string>
namespace assignment2 {

// operators supported by our calculator
enum Operator { PLUS, MINUS, TIMES, DIVIDE };

// convert an Operator to its string representation
auto rep(Operator o) -> std::string;

// convert a character to an operator
// throws an exception if the conversion cannot be completed
auto parse(char c) -> Operator;
} // namespace assignment2

#endif // ASSIGNMENT_2_OPERATOR_HPP
