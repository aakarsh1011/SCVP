add_executable(practice
    #nand_main.cpp
    main2.cpp
    )

target_include_directories(practice
    PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(practice
    PRIVATE ${SYSTEMC_LIBRARY}
)
