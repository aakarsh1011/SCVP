add_executable(SC_FIFO
main2.cpp
)

target_include_directories(SC_FIFO
    PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(SC_FIFO
    PRIVATE ${SYSTEMC_LIBRARY}
)
