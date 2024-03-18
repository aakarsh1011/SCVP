#include <systemc.h>


SC_MODULE(Add) {
    sc_fifo_in<unsigned int> a, c;
    sc_fifo_out<unsigned int> b;

    void process() {
        while (true) {
            unsigned int input_a = a.read();
            unsigned int input_c = c.read();
            unsigned int result = input_a + input_c;
            b.write(result);
        }
    }

    SC_CTOR(Add) {
        SC_THREAD(process);
    }
};

SC_MODULE(Split) {
    sc_fifo_in<unsigned int> b;
    sc_fifo_out<unsigned int> a, d;
    sc_signal<unsigned int> e;

    void process() {
        int count = 0;
        while (count < 10) { // Stop after 10 prints
            unsigned int input_b = b.read();
            a.write(input_b);
            d.write(input_b);
            e = input_b;
            cout << "Output e: " << e << endl;
            count++;
        }
        sc_stop(); // Stop simulation after 10 prints
    }

    SC_CTOR(Split) {
        SC_THREAD(process);
    }
};

SC_MODULE(Delay) {
    sc_fifo_in<unsigned int> d;
    sc_fifo_out<unsigned int> c;

    void process() {
        while (true) {
            unsigned int input_d = d.read();
            c.write(input_d);
        }
    }

    SC_CTOR(Delay) {
        SC_THREAD(process);
    }
};

int sc_main(int argc, char* argv[]) {
    // Define FIFOs
    sc_fifo<unsigned int> fifo_a(10);
    sc_fifo<unsigned int> fifo_b(10);
    sc_fifo<unsigned int> fifo_c(10);
    sc_fifo<unsigned int> fifo_d(10);

    // Initialize FIFOs
    fifo_b.write(1); // Initialize fifo_b with value 1
    fifo_c.write(0); // Initialize fifo_c with value 0

    // Instantiate modules
    Add add("add");
    Split split("split");
    Delay delay("delay");

    // Connect modules
    add.a(fifo_a);
    add.c(fifo_c);
    add.b(fifo_b);

    split.b(fifo_b);
    split.a(fifo_a);
    split.d(fifo_d);
    //split.e(fifo_c); // Connect e to fifo_c

    delay.d(fifo_d);
    delay.c(fifo_c);

    // Start simulation
    sc_start();

    return 0;
}
