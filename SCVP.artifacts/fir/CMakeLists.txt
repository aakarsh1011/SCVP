add_executable(fir
main.cpp
)

target_include_directories(fir
    PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(fir
    PRIVATE ${SYSTEMC_LIBRARY}
)
