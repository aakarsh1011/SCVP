
#ifndef ADD_H
#define ADD_H


#include<systemc.h>


// Split module (add.h)
SC_MODULE(ADD){
    sc_fifo_in<unsigned int> a, c;
    sc_fifo_out<unsigned int> b;

    void process(){
        while (true){
        unsigned int input_a = a.read();
        unsigned int input_c = c.read();
        unsigned int output_b = input_a + input_c;
        b.write(output_b);};
    }

    SC_CTOR(ADD){
        SC_THREAD(process);
    }
};

#endif