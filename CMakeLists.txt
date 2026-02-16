cmake_minimum_required(VERSION 3.10)
project(List C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Library

add_library(List src/List.c)
target_include_directories(List PUBLIC include)
target_compile_options(List PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)

# Testing

add_subdirectory(extern/unity)

enable_testing()

# Test executables

add_executable(test__List test/List.c)
target_link_libraries(test__List PRIVATE List unity)
add_test(NAME Test:List COMMAND test__List)
