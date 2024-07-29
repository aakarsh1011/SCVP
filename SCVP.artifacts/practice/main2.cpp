#include <systemc.h>
#include "stim.h"
#include"mon.h"

using namespace std;

SC_MODULE(orgate)
{
    public:
        sc_in<bool> in1;
        sc_in<bool> in2;
        sc_out<bool> out;

    SC_CTOR(orgate)
    {
        SC_METHOD(process);
        sensitive << in1 << in2;
    };

    void process()
    {
        out.write(in2.read() || in2.read());
    };

};

SC_MODULE(andgate)
{
    public:

        sc_in<bool> in1;
        sc_in<bool> in2;
        sc_out<bool> out;

    SC_CTOR(andgate)
    {
        SC_METHOD(process);
        sensitive << in1 << in2;
    };

    void process()
    {
        out.write(in1.read() && !(in2.read()));
    };
};

SC_MODULE(circuit)
{
    public:
    sc_signal<bool> h1;
    sc_in<bool> A, B;
    sc_out<bool> Z;

    orgate o1;
    andgate a1;

    SC_CTOR(circuit): A("A"), B("B"), Z("Z"), a1("a1"), o1("o1")
    {
        o1.in1(Z);
        o1.in2(B);
        o1.out(h1);

        a1.in1(h1);
        a1.in2(A);
        a1.out(Z);

        SC_METHOD(process);
        sensitive << A << B << Z;
    };

    void process()
    {

    };

};

int sc_main(int, char**)
{
    
    sc_signal<bool> A, B, Z;

    sc_clock clock("Clk", 10, SC_NS, 0.5);

    stim Stim1("stimulus");
    Stim1.A(A);
    Stim1.B(B);
    Stim1.Clk(clock);


    circuit ckt("ckt");
    ckt.A(A);
    ckt.B(B);
    ckt.Z(Z);

    Monitor mon("Monitor");
    mon.A(A);
    mon.B(B);
    mon.Z(Z);
    mon.Clk(clock);


    sc_start();

    return 0;


}