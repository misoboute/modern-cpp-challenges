include(ExternGoogleTest)

find_package(GTest QUIET)

if (GTest_FOUND)
    add_subdirectory(chapter01)
else()
    message(WARNING 
"GoogleTest not found. It is supposed to be retrieved and built during the \
very first build after generating is done. Skipping generation of tests now. \
Build the tree once and generate the build system again to add the tests.")
endif()

