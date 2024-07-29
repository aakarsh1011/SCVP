#ifndef ANDGATE_H
#define ANDGATE_H

#include<systemc.h>

SC_MODULE(andgate)
{
    public:
    sc_in<bool> and_in_one;
    sc_in<bool> and_in_two;
    sc_out<bool> out;


    SC_CTOR(andgate)
    {
        SC_METHOD(process);
        sensitive << and_in_one << and_in_two;
    };

    void process()
    {
        out.write(and_in_one.read() && !(and_in_two.read()));
    };

};

#endif