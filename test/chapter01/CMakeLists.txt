find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
add_definitions(-DGTEST_LANG_CXX11=1)

set(SOURCES 
    primenumbers.cpp
    problem01.cpp
    problem02.cpp
    problem03.cpp
    problem04.cpp
    problem05.cpp
)

include_directories(${MODCPPCHAL_REPO_ROOT}/include)

add_executable(chapter01_test ${SOURCES})

target_link_libraries(chapter01_test
    Threads::Threads
    ${GTEST_BOTH_LIBRARIES}
)
