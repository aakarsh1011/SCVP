add_executable(Exercise_2
main.cpp
state_machine.cpp
stimuli.cpp
)

target_include_directories(Exercise_2
    PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(Exercise_2
    PRIVATE ${SYSTEMC_LIBRARY}
)
