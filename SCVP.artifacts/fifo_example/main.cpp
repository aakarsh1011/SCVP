#include <systemc.h>

SC_MODULE(Add) {
    sc_fifo_in<unsigned int> a, c;
    sc_fifo_out<unsigned int> b;

    SC_CTOR(Add) {
        SC_THREAD(add_process);
    }

    void add_process() {
        while (true) {
            unsigned int input_a = a.read();
            unsigned int input_c = c.read();
            unsigned int sum = input_a + input_c;
            b.write(sum);
        }
    }
};

SC_MODULE(Split) {
    sc_fifo_in<unsigned int> b;
    sc_fifo_out<unsigned int> a, d;
    sc_out<unsigned int> e;

    SC_CTOR(Split) {
        SC_THREAD(split_process);
    }

    void split_process() {
        int print_count = 0;
        while (print_count < 10) {
            unsigned int input_b = b.read();
            a.write(input_b);
            d.write(input_b);
            e.write(input_b);

            // Print the output e
            cout << "e: " << input_b << endl;

            print_count++;
        }

        // Stop simulation after 10 prints
        sc_stop();
    }
};

SC_MODULE(Delay) {
    sc_fifo_in<unsigned int> d;
    sc_fifo_out<unsigned int> c;

    SC_CTOR(Delay) {
        SC_THREAD(delay_process);
    }

    void delay_process() {
        while (true) {
            unsigned int input_d = d.read();
            c.write(input_d);
        }
    }
};

int sc_main(int argc, char *argv[]) {
    // FIFOs initialization
    sc_fifo<unsigned int> fifo_b(10);
    sc_fifo<unsigned int> fifo_c(10);

    // Modules instantiation
    Add add_process("Add");
    Split split_process("Split");
    Delay delay_process("Delay");

    // Connections
    add_process.b(fifo_b);
    split_process.b(fifo_b);
    split_process.a(fifo_b);
    split_process.d(fifo_c);
    delay_process.d(fifo_c);
    delay_process.c(fifo_c);

    // Start simulation
    sc_start();

    return 0;
}
