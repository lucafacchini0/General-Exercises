cmake_minimum_required(VERSION 3.10)

# Set the project name
project(StudentManager)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(StudentManager main.cpp)

# Include directories
include_directories(${PROJECT_SOURCE_DIR})

# Add other source files if needed
target_sources(StudentManager student.h)
# target_sources(StudentManager PRIVATE student.cpp)