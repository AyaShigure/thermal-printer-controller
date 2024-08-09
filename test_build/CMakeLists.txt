# CMakeLists.txt

# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(execute_print)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the compiler to x86_64 cross-compiler
set(CMAKE_CXX_COMPILER x86_64-linux-gnu-gcc)

# Add an executable target
add_executable(execute_print
    src/main.cpp
    src/cmdtestfunction.cpp
    src/cmdtestunit.cpp
    src/cmdtestutils.cpp
)

# Include directories
target_include_directories(execute_print PUBLIC
    include
    src
    lib
)

# Link libraries
target_link_libraries(execute_print PUBLIC
    ${CMAKE_SOURCE_DIR}/lib/libautoreplyprint.a
    stdc++
    m
    pthread
)

