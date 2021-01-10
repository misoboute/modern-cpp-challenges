include(ExternalProject)

ExternalProject_Add(
    ExternProjGoogleTest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.10.0
    GIT_SHALLOW TRUE
    UPDATE_DISCONNECTED TRUE
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
)

ExternalProject_Get_Property(ExternProjGoogleTest INSTALL_DIR)
list(APPEND CMAKE_PREFIX_PATH ${INSTALL_DIR})
