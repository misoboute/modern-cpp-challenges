set(SOURCES 
    primenumbers.cpp
    problem01.cpp
    problem02.cpp
    problem03.cpp
    problem04.cpp
    problem05.cpp
)

include_directories(${MCC_REPO_ROOT}/include)

add_executable(chapter01_test ${SOURCES})

target_link_libraries(chapter01_test GTest::gmock_main)
