cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
# Required for nlohmann/json at least:
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MCC_REPO_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

list(APPEND CMAKE_MODULE_PATH ${MCC_REPO_ROOT}/cmake)

project(modcppchal)

add_subdirectory(src)
add_subdirectory(test)
