cmake_minimum_required (VERSION 3.11)
project (snail_engine)

#set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 11)

# Setting version number
set (snail_engine_release_version 0)

set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/build)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Configure a header file to pass some of the CMake settings
# to the source code
configure_file (
	"${PROJECT_SOURCE_DIR}/engine_config.h.in"
	"${PROJECT_SOURCE_DIR}/engine_config.h"
)

include_directories("D:\\projects\\libraries\\sdl2\\include\\SDL2")

# add the binary tree to the search path for include files
include_directories("${PROJECT_BINARY_DIR}")
add_subdirectory("engine")

# add executable
add_executable(snail_engine main.cpp)
target_link_libraries(snail_engine snail_core)
