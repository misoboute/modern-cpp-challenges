include_directories(${MODCPPCHAL_REPO_ROOT}/include)

set(SOURCES
    math.cpp
)

add_library(math ${SOURCES})

add_subdirectory(chapter01)
