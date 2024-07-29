add_executable(fifo_example
    main.cpp
)

target_include_directories(fifo_example
    PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(fifo_example
    PRIVATE ${SYSTEMC_LIBRARY}
)
