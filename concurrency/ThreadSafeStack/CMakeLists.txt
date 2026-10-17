cmake_minimum_required(VERSION 3.16)
project(StackExample LANGUAGES CXX)

find_package(Threads REQUIRED)

add_executable(StackExample main.cpp)
target_compile_features(StackExample PRIVATE cxx_std_17)
target_link_libraries(StackExample PRIVATE Threads::Threads)
