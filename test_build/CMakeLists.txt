# CMakeLists.txt

# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(printer_control)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the compiler to x86_64 cross-compiler
set(CMAKE_CXX_COMPILER x86_64-linux-gnu-gcc)

# Create a directory for built binaries
set(python_wrapper_dir ./python_wrapper)
file(MAKE_DIRECTORY ${python_wrapper_dir})
# Target binary list
set(target_list Test_print;Picture_printer)

foreach(loop_var IN LISTS target_list)
    message("** Setting up target: ${loop_var}")

    # Add an executable target
    add_executable(${loop_var}
        src/main_${loop_var}.cpp
        src/cmdtestfunction.cpp
        src/cmdtestunit.cpp
        src/cmdtestutils.cpp
    )

    # Include directories
    target_include_directories(${loop_var} PUBLIC
        include
        src
        lib
    )

    # Link libraries
    target_link_libraries(${loop_var} PUBLIC
        ${CMAKE_SOURCE_DIR}/lib/libautoreplyprint.a
        stdc++
        m
        pthread
    )

endforeach()
