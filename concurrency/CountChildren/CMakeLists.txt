cmake_minimum_required(VERSION 3.16)
project(CountChildren LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Threads REQUIRED)

add_executable(CountChildren main.cpp)
target_compile_features(CountChildren PRIVATE cxx_std_17)
target_link_libraries(CountChildren PRIVATE Threads::Threads)
