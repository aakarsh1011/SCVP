cmake_minimum_required(VERSION 3.10)

project(Exercise_6)

add_executable(Exercise_6
    main2.cpp
)

target_include_directories(Exercise_6
    PRIVATE $ENV{SYSTEMC_HOME}/include/
)

find_library(SYSTEMC_LIBRARY 
    NAMES systemc
    PATHS $ENV{SYSTEMC_HOME}/lib-$ENV{SYSTEMC_TARGET_ARCH}/
)

target_link_libraries(Exercise_6
    PRIVATE ${SYSTEMC_LIBRARY}
)
