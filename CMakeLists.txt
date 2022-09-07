cmake_minimum_required(VERSION 3.14)
project("Assignment 2")

include(FetchContent)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

FetchContent_Declare(fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 8.1.1
)
FetchContent_MakeAvailable(fmt)

# add our cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

find_package(Doctest REQUIRED)

include(cmake/ClangFormat.cmake)
include(CTest)

# Now set up clang-tidy
find_program(CLANG_TIDY_EXE NAMES "clang-tidy" REQUIRED)
set(CLANG_TIDY_COMMAND "${CLANG_TIDY_EXE}" "-checks=-*,modernize-*")

add_library(Stack assignment2/Node.hpp assignment2/Operator.cpp assignment2/Operator.hpp assignment2/Stack.hpp assignment2/Stack.cpp)
set_target_properties(Stack PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}")
target_link_libraries(Stack fmt)

add_library(RpnCalculator assignment2/RpnCalculator.cpp assignment2/RpnCalculator.hpp)
set_target_properties(RpnCalculator PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}")
target_link_libraries(RpnCalculator Stack fmt)

add_executable(StackTest assignment2/Stack.test.cpp)
target_compile_features(StackTest PRIVATE cxx_std_17)
target_link_libraries(StackTest Doctest Stack fmt)
add_test(NAME StackTest COMMAND StackTest)

add_executable(RpnCalculatorTest assignment2/RpnCalculator.test.cpp)
target_compile_features(RpnCalculatorTest PRIVATE cxx_std_17)
target_link_libraries(RpnCalculatorTest Doctest RpnCalculator Stack fmt)
add_test(NAME RpnCalculatorTest COMMAND RpnCalculatorTest)
