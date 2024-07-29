#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H
using namespace std;

#include <systemc.h>

enum base {Start, G, GA, GAA, GAAG };

SC_MODULE(stateMachine)
{
    public:
        sc_in<char> input;
        sc_in<bool> clk;

        

    SC_CTOR(process):
        input("input"), clk("clk")
        {
            SC_METHOD(process);
        }

    void process()
    {
        case Start:

    }

}