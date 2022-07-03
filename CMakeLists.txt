cmake_minimum_required(VERSION 3.14)
project("Assignment 2")

include(FetchContent)

set(CMAKE_CXX_STANDARD 17)

FetchContent_Declare(fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 8.1.1
)
FetchContent_MakeAvailable(fmt)

# add our cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

find_package(Doctest REQUIRED)

include(cmake/ClangFormat.cmake)

enable_testing()

# Now set up clang-tidy
find_program(CLANG_TIDY_EXE NAMES "clang-tidy" REQUIRED)
set(CLANG_TIDY_COMMAND "${CLANG_TIDY_EXE}" "-checks=-*,modernize-*")

add_library(LinkedList assignment2/Node.hpp assignment2/Operator.cpp assignment2/Operator.hpp assignment2/Stack.hpp)
set_target_properties(LinkedList PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}")