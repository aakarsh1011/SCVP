add_executable(Exercise_1
    #nand_main.cpp
    exor_main.cpp
    )

target_include_directories(Exercise_1
    PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(Exercise_1
    PRIVATE ${SYSTEMC_LIBRARY}
)
