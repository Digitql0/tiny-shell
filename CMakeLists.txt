cmake_minimum_required(VERSION 3.10)
project(ModularTerminal)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Include directories
include_directories(include)

# Gather all source files
file(GLOB_RECURSE MAIN_SRC src/*)

# Create executable
add_executable(modular-terminal
    ${MAIN_SRC}
)
