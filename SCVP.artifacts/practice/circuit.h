#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "andgate.h"
#include "orgate.h"

#include<systemc.h>

using namespace std;

SC_MODULE(circuit)
{
    sc_in<bool> A, B;
    sc_out<bool> Z;
    sc_signal<bool> h1;

    andgate a1;
    orgate o1;

    SC_CTOR(circuit): A("A"), B("B"), Z("Z"), h1("h1"), a1("a1"), o1("o1")
    {
        a1.and_in_one(h1);
        a1.and_in_two(B);
        a1.out(Z);

        o1.or_in_one(Z);
        o1.or_in_two(A);
        o1.out(h1);


        SC_METHOD(do_circuit);
        sensitive << A << B << Z;
    };

    void do_circuit()
    {

    };


};

#endif