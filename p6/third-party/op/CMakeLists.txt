cmake_minimum_required(VERSION 3.8)

add_library(op INTERFACE)
add_library(op::op ALIAS op)
target_compile_features(op INTERFACE cxx_std_11)
target_include_directories(op INTERFACE include)