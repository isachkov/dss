cmake_minimum_required(VERSION 3.16)

project(dss_lib)

set(DSS_LIB_SRC 
    Entry.cpp 
    Node.cpp)

add_library(dss_lib STATIC ${DSS_LIB_SRC})

target_compile_features(dss_lib PUBLIC cxx_std_17)