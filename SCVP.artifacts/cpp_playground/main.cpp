#include <iostream>
#include <systemc.h>
using namespace std;

SC_MODULE(adder)
{
    public:
    {
        sc_in<int> A;
        sc_in<int> B;
        sc_out<int> C;
    }

    SC_CTOR(adder): A("A"), B("B"), C("C")
    {
        SC_METHOD(compute);
        sensitive << A << B;
    }

    void compute()
    {
        C.write(A.read() + B.read());
        cout << A << "+" << B << C;

    }
};

// #include "state_machine.h"
// #include "stimuli.h"

// int sc_main(int, char**)
// {
//     stateMachine genomeParser("genomeParser");
//     stimuli genomeInput("genomeInput");
//     sc_clock clk("clk", sc_time(1, SC_NS));

//     sc_signal<char> h1;

//     genomeParser.input.bind(h1);
//     genomeInput.output.bind(h1);
//     genomeParser.clk.bind(clk);
//     genomeInput.clk.bind(clk);

//     sc_start();

//     return 0;
// }
