cmake_minimum_required(VERSION 3.10)

project(Maze)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(maze main.cpp)

# Include directories
target_include_directories(maze PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/cell.cpp
    src/maze.cpp
)

# Add source files to the executable
target_sources(maze PRIVATE ${SOURCES})

