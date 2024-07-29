add_executable(srlatch
main.cpp
)

target_include_directories(srlatch
    PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(srlatch
    PRIVATE ${SYSTEMC_LIBRARY}
)
