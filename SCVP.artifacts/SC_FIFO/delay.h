
#ifndef DELAY_H
#define DELAY_H


#include<systemc.h>


// Split module (add.h)
SC_MODULE(DELAY){
    sc_fifo_in<unsigned int> d;
    sc_fifo_out<unsigned int> c;

    void process(){
        while (true){
        unsigned int input_d = d.read();
    
        c.write(input_d);};
    }

    SC_CTOR(DELAY){
        SC_THREAD(process);
    }
};

#endif