cmake_minimum_required(VERSION 3.14)

project("SOME ASSIGNMENT")

set(CMAKE_CXX_STANDARD 17)

# add our cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

find_package(Doctest REQUIRED)

include(cmake/ClangFormat.cmake)

enable_testing()

# Now set up clang-tidy
find_program(CLANG_TIDY_EXE NAMES "clang-tidy" REQUIRED)
set(CLANG_TIDY_COMMAND "${CLANG_TIDY_EXE}" "-checks=-*,modernize-*")
