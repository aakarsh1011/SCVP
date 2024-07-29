add_executable(simplefifor
main.cpp
)

target_include_directories(simplefifor
    PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(simplefifor
    PRIVATE ${SYSTEMC_LIBRARY}
)
