cmake_minimum_required(VERSION 3.0)

project(tlm_lt_intiator_target)

add_executable(tlm_lt_initiator_target
    main.cpp
)

target_include_directories(tlm_lt_initiator_target
    PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(tlm_lt_initiator_target
    PRIVATE ${SYSTEMC_LIBRARY}
)
