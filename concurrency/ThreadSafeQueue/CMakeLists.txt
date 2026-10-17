cmake_minimum_required(VERSION 3.16)
project(QueueExample LANGUAGES CXX)

find_package(Threads REQUIRED)

add_executable(QueueExample main.cpp)
target_compile_features(QueueExample PRIVATE cxx_std_17)
target_link_libraries(QueueExample PRIVATE Threads::Threads)
