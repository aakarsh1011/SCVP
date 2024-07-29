#include <systemc.h>

// module for registers
SC_MODULE(registor)
{
public:
    sc_in<bool> clk;
    sc_in<bool> reset;
    sc_in<int> input;
    sc_out<int> output;

    SC_CTOR(registor)
    {
        SC_METHOD(process);
        sensitive << clk.pos();
        sensitive << reset;
    }

    void process()
    {
        if (reset.read() == true)
        {
            output.write(0);
        }
        else if (clk.posedge())
        {
            output.write(input.read());
        }
    }
};

// module for adder
SC_MODULE(adder)
{
public:
    sc_in<int> in1;
    sc_in<int> in2;
    sc_out<int> out;

    SC_CTOR(adder)
    {
        SC_METHOD(process);
        sensitive << in1 << in2;
    }

    void process()
    {
        out.write(in1.read() + in2.read());
    }
};

int sc_main(int argc, char* argv[])
{
    // Define signals
    sc_signal<int> d_in, h1, h2, h3, o1, o2, d_out;
    sc_signal<bool> reset;
    sc_clock clk("clk", 10, SC_NS); // 10 ns clock period

    // Instantiate modules
    registor r1("r1"), r2("r2"), r3("r3");
    adder a1("a1"), a2("a2"), a3("a3");

    // Connect signals to r1
    r1.input(d_in);
    r1.output(h1);
    r1.clk(clk);
    r1.reset(reset);

    // Connect signals to r2
    r2.input(h1);
    r2.output(h2);
    r2.clk(clk);
    r2.reset(reset);

    // Connect signals to r3
    r3.input(h2);
    r3.output(h3);
    r3.clk(clk);
    r3.reset(reset);

    // Connect signals to a1
    a1.in1(d_in);
    a1.in2(h1);
    a1.out(o1);

    // Connect signals to a2
    a2.in1(o1);
    a2.in2(h2);
    a2.out(o2);

    // Connect signals to a3
    a3.in1(o2);
    a3.in2(h3);
    a3.out(d_out);

    // Initialize signals
    d_in.write(1);
    reset.write(false);

    // Start simulation
    sc_start(100, SC_NS);

    // Print the output
    std::cout << "Output: " << d_out.read() << std::endl;

    return 0;
}
