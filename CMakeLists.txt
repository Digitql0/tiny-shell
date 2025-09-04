cmake_minimum_required(VERSION 3.10)
project(tinyShell LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

add_subdirectory(external/Data-Structures-Collection)

# Collect sources
file(GLOB_RECURSE LIB_SOURCES CONFIGURE_DEPENDS
    src/*.cpp
    src/*.c
)
list(REMOVE_ITEM LIB_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.c")

# Build as a static library
add_library(tinyShell STATIC ${LIB_SOURCES})
target_include_directories(tinyShell PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(tinyShell PUBLIC dataStructures)

set(APP_SOURCES src/main.c)

# Build as an Executable
add_executable(tinyShellApp ${APP_SOURCES})
target_link_libraries(tinyShellApp PRIVATE tinyShell)
