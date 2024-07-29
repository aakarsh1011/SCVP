#ifndef SR_LATCH_H
#define SR_LATCH_H

#include<systemc.h>
#include "nand.h"

SC_MODULE(srLatch)
{
    public:
        sc_in<bool> S;
        sc_in<bool> R;
        sc_out<bool> Z1;
        sc_out<bool> Z2;
        sc_signal<bool> h1;
        sc_signal<bool> h2;

        nand n1, n2;

    SC_CTOR(srLatch)
    :n1("n1"), n2("n2"),
    S("S"), R("R"), Z1("Z1"), Z2("Z2")

    {
        n1.A(S);
        n1.B(Z2);
        n1.Z(Z1);

        n2.A(Z1);
        n2.B(R);
        n2.Z(Z2);

        SC_METHOD(do_sr);
        sensitive << S << R;
    };

    void do_sr()
    {
        //Already implemented
    }

};

#endif