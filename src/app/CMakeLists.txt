cmake_minimum_required(VERSION 3.16)

project(dss_app)

set(DSS_APP_SRC 
    main.cpp)

add_executable(dss_sample ${DSS_APP_SRC})

target_link_libraries(dss_sample PRIVATE dss_lib)