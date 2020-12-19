cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
# Required for nlohmann/json at least:
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(modcppchal)

set(MODCPPCHAL_REPO_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(src)
add_subdirectory(test)
