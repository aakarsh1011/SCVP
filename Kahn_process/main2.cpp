#include<systemc.h>

#include "Split.h"
#include "add.h"
#include "delay.h"


int sc_main(int argc, char* argv[]){

    sc_fifo<unsigned int> fifo_a(10);
    sc_fifo<unsigned int> fifo_b(10);
    sc_fifo<unsigned int> fifo_c(10);
    sc_fifo<unsigned int> fifo_d(10);

    fifo_b.write(1);
    fifo_c.write(0);

    // Instantiate modules
    ADD add("add");
    SPLIT split("split");
    DELAY delay("delay");

    add.a(fifo_a);
    add.c(fifo_c);
    add.b(fifo_b);

    split.b(fifo_b);
    split.d(fifo_d);
    split.a(fifo_a);

    delay.d(fifo_d);
    delay.c(fifo_c);

    sc_start();

    return 0;

};