include_directories(${MCC_REPO_ROOT}/include/mathutils)

set(SOURCES
    IntDivisors.cpp
    PrimeNumbers.cpp
    mathutils.cpp
)

add_library(mathutils ${SOURCES})
