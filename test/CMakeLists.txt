cmake_minimum_required(VERSION 3.16)

project(dss_test)

set(DSS_TEST_SRC sample_case.cpp main.cpp)

add_executable(dss_test ${DSS_TEST_SRC})

target_link_libraries(dss_test PRIVATE dss_lib Catch2)
