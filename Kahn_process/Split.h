#ifndef SPLIT_H
#define SPLIT_H


#include<systemc.h>


// Split module (Split.h)
SC_MODULE(SPLIT){
    sc_fifo_in<unsigned int> b;
    sc_fifo_out<unsigned int> a, d;
    sc_signal<unsigned int> e;

    void process(){
        int count = 0;
        while(count <10){
            unsigned int input_b = b.read();
            a.write(input_b);
            d.write(input_b);
            e = input_b;
            count++;

            std::cout << "Output e: " << e << std::endl;
        }
        sc_stop();

    }

    SC_CTOR(SPLIT)
    {
        SC_THREAD(process);
    }
};

#endif