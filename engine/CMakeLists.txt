cmake_minimum_required (VERSION 3.11)
project (snail_core)

# Setting version number
#set (snail_engine_bugs_fixed 0)
#set (snail_engine_features_implemented 0)

#set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/build)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Configure a header file to pass some of the CMake settings
# to the source code
# todo: add version file to track 
#configure_file (
#	"${PROJECT_SOURCE_DIR}/engine_config.h.in"
#	"${PROJECT_SOURCE_DIR}/engine_config.h"
#)

# add the binary tree to the search path for include files
include_directories("${PROJECT_BINARY_DIR}")

# add executable
add_library(snail_core engine.h engine.cpp)
