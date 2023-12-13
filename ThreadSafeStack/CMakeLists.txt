cmake_minimum_required(VERSION 3.0)
project(StackExample)

# Set C++ standard to C++17 or later
set(CMAKE_CXX_STANDARD 17)

# Define the sources for your project (Stack class and main.cpp)
set(SOURCES
    main.cpp
)

# Add an executable target
add_executable(StackExample ${SOURCES})