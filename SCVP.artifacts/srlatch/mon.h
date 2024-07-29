#ifndef MONITOR_H
#define MONITOR_H

#include <iostream>
#include <systemc.h>

SC_MODULE(Monitor)
{
public:
    sc_in<bool> S, R, Q, Q_bar, Clk;

    SC_CTOR(Monitor)
    {
        std::cout << std::endl << "time\tS\tR\tQ\tQ_bar" << std::endl;
        SC_METHOD(monitor);
        sensitive << Clk.pos();
        dont_initialize();
    }

private:
    void monitor()
    {
        std::cout << sc_time_stamp() << "\t" << S.read() << "\t" << R.read() << "\t" << Q.read() << "\t" << Q_bar.read() << std::endl;
    }
};

#endif
