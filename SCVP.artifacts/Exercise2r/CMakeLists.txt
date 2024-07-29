add_executable(Exercise2r
main.cpp
state_machine.cpp
stimuli.cpp
)

target_include_directories(Exercise2r
    PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(Exercise2r
    PRIVATE ${SYSTEMC_LIBRARY}
)
