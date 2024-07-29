#ifndef EXOR_H
#define EXOR_H

#include <systemc.h>
#include "nand.h"

SC_MODULE(exor)
{
public:
    sc_in<bool> A, B;
    sc_out<bool> Z;
    sc_signal<bool> h1, h2, h3;

    nand n1, n2, n3, n4;

    SC_CTOR(exor)
        : n1("n1"), n2("n2"), n3("n3"), n4("n4"),
          A("A"), B("B"), Z("Z"), h1("h1"), h2("h2"), h3("h3")
    {
        n1.A(A);
        n1.B(B);
        n1.Z(h1);

        n2.A(h1);
        n2.B(B);
        n2.Z(h2);

        n3.A(A);
        n3.B(h1);
        n3.Z(h3);

        n4.A(h3);
        n4.B(h2);
        n4.Z(Z);

        SC_METHOD(do_exor);
        sensitive << A << B;
    }

    void do_exor()
    {
        // The connections are already set up in the constructor
        // No need to repeat them here.
    }
};

#endif
