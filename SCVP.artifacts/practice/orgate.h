#ifndef ORGATE_H
#define ORGATE_H

#include <systemc.h>

using namespace std;


SC_MODULE(orgate)
{
    public:
    sc_in<bool> or_in_one;
    sc_in<bool> or_in_two;
    sc_out<bool> out;

    SC_CTOR(orgate)
    {
        SC_METHOD(process);
        sensitive << or_in_one << or_in_two;
    };


    void process()
    {
        out.write(or_in_one.read() || or_in_two.read());
    }

};

#endif