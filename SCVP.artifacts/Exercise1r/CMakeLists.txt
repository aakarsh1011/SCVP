add_executable(Exercise1r
    #nand_main.cpp
    exor_main.cpp
    )

target_include_directories(Exercise1r
    PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(Exercise1r
    PRIVATE ${SYSTEMC_LIBRARY}
)