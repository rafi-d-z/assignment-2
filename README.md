# Assignment 2

In this assignment, you'll implement an RPN calculator using a stack. However,
you'll first need to implement the stack using a linked list.

## Step One: Implement a Stack

`assignment2/Stack.hpp` is the header file for a basic stack class backed by a linked list.
The nodes of the linked list are defined by the `Node` struct in `assignment2/Node.hpp`.
The data in the nodes are of type [std::variant](https://en.cppreference.com/w/cpp/utility/variant),
which is a union type--it can either be an `Operator` (an enum defined in `assignment2/Operator.hpp`) or
a double. (See `assignment2/Node.test.cpp` for some examples of working with `variant` and `Node`.)

Implement the prototypes from the header file in `assignment2/Stack.cpp`. Make sure the tests
pass. 

To build/run the tests for the `Stack` class *only*:
```bash
cd build
cmake ..
cmake --build . --target StackTest
ctest -V -R StackTest
```

## Step Two: Use your stack to implement an RPN calculator

Typically, when we write arithmetic expressions, we use *infix notation* where the operator comes between
the operands: `2 + 2`. In [Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation),
the operator comes last: `2 2 +`. HP calculators famously use(d) RPN because it's particularly easy for
computers to use. (See the [Museum of HP Calculators](https://www.hpmuseum.org/rpn.htm) for a brief explanation
of why.) There's also no need to worry about operator precendence (you might have learned PEMDAS or BEMDAS in school)
and parentheses.

You need to implement the following methods in `RpnCalculator.cpp`:
- `Value` -- return the result of the calculation
- `Push` -- push an element onto the calculator's stack (**hint**: if it's an `Operator`, you need to actually perform the calculation in this function)

## How To:
- Run valgrind: in the `build` directory, run `ctest -T memcheck`
- Run clang-format: in the `build` directory, run `cmake --build . --target format_all`

## Odds and Ends

- There is a `.devcontainer` directory that should allow you use a remote development container in VSCode.
(I do intend to just publish a docker image so we don't build a new one for each assignment, just spin up a new container.)
- The bash script `scripts/zip_assignment.sh` is the same as last time.