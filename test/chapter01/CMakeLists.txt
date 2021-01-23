set(SOURCES 
    primenumbers.cpp
    problem01.cpp
    problem02.cpp
    problem03.cpp
    problem04.cpp
    problem05.cpp
    problem06.cpp
    problem07.cpp
    problem08.cpp
    problem09.cpp
)

include_directories(${MCC_REPO_ROOT}/include/mathutils)

add_executable(chapter01_test ${SOURCES})

target_link_libraries(chapter01_test mathutils GTest::gmock_main)
