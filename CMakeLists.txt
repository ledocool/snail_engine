cmake_minimum_required (VERSION 3.11)
project (snail_engine)

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

# add the binary tree to the search path for include files
include_directories("${PROJECT_BINARY_DIR}")

# add executable
add_executable(snail_engine main.cpp)