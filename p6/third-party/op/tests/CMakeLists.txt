cmake_minimum_required(VERSION 3.8)
project(op-tests)

add_executable(${PROJECT_NAME} test.cpp)
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /WX /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Werror -Wall -Wextra -Wpedantic -pedantic-errors -Wconversion -Wsign-conversion)
endif()

# ---Add op---
add_subdirectory(.. op-tests)
target_link_libraries(${PROJECT_NAME} op::op)

## ---Add doctest---
add_subdirectory(doctest)
target_link_libraries(${PROJECT_NAME} doctest::doctest)