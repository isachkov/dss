cmake_minimum_required(VERSION 3.16)

project(dss_lib)

aux_source_directory(dss DSS_LIB_SRC)

add_library(dss_lib STATIC ${DSS_LIB_SRC})

target_compile_features(dss_lib PUBLIC cxx_std_17)
target_include_directories(dss_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})