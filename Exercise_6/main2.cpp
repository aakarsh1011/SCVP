#include <iostream>
#include <iomanip>
#include <systemc.h>

#include "memory.h"
#include "processor.h"
#include "bus.h"


int sc_main (int __attribute__((unused)) sc_argc,
             char __attribute__((unused)) *sc_argv[])
{
    
    processor cpu0("cpu0", "/home/aakarsh/SCVP.artifacts/Exercise_6/stimuli1.txt", sc_time(1, SC_NS));
    processor cpu1("cpu1", "/home/aakarsh/SCVP.artifacts/Exercise_6/stimuli2.txt", sc_time(1, SC_NS));
    memory<512> memory0("memory0");
    memory<512> memory1("memory1");

    bus bus("bus");



    // TODO: add your code here
    cpu0.iSocket.bind(bus.tSocket[0]);
    cpu1.iSocket.bind(bus.tSocket[1]);
    memory0.tSocket.bind(bus.iSocket[0]);
    memory1.tSocket.bind(bus.iSocket[1]);

    

    std::cout << std::endl << "Name "
              << std::setfill(' ') << std::setw(10)
              << "Time" << " "
              << std::setfill(' ') << std::setw(5)
              << "CMD" << "   "
              << std::setfill(' ') << std::setw(8)
              << "Address"
              << "   " << std::hex
              << std::setfill(' ') << std::setw(8)
              << "Data"
              << " " << std::endl
              << "-------------------------------------------"
              << std::endl;

    sc_start();

    std::cout << std::endl;
    return 0;
}