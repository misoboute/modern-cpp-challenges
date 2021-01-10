include_directories(${MCC_REPO_ROOT}/include)

set(SOURCES
    mathutils.cpp
)

add_library(math ${SOURCES})

add_subdirectory(chapter01)
