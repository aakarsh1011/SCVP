#include <systemc.h>
#include "place.h"
#include "transition.h"
#include "subnet.h"

// Toplevel SC_MODULE
template <unsigned int Win = 1, unsigned int Wout = 1, unsigned int L = 0>
SC_MODULE(TopLevel)
{
    // Places and transitions
    placeChannel<Win, Wout> IDLE{"IDLE"};

    Subnet <Win, Wout, L> s1{"S1"};
    Subnet <Win, Wout, L> s2{"S2"};

    // Constructor
    SC_CTOR(TopLevel): 
    IDLE(2), s1("subnet1"), s2("subnet2")
    {
        // Connect transitions and places

        s1.ACT.in(IDLE);
        s2.ACT.in(IDLE);

        s1.PRE.out(IDLE);
        s2.PRE.out(IDLE);

        //ACT.out(ACTIVE);
        //ACT.in(IDLE);

        //RD.out(ACTIVE);
        //RD.in(ACTIVE);

        //PRE.out(IDLE);
        //PRE.in(ACTIVE);

        //WR.out(ACTIVE);
        //WR.in(ACTIVE);

        SC_THREAD(process);
    }

    // Test bench process
    void process()
    {
        while (true)
        {   
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s1.RD.fire();
            wait(10, SC_NS);
            s1.WR.fire();
            wait(10, SC_NS);
            s1.PRE.fire();
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s2.ACT.fire();
            wait(10, SC_NS);
            s2.ACT.fire();
            wait(10, SC_NS);
            s1.PRE.fire();
            wait(10, SC_NS);
            s2.PRE.fire();
            wait(10, SC_NS);
            sc_stop();

            //wait(10, SC_NS);
            //ACT.fire();
            //wait(10, SC_NS);
            //ACT.fire();
            //wait(10, SC_NS);
            //RD.fire();
            //wait(10, SC_NS);
            //WR.fire();
            //wait(10, SC_NS);
            //PRE.fire();
            //wait(10, SC_NS);
            //ACT.fire();
            //sc_stop();
        }
    }
};

int sc_main(int argc, char *argv[])
{
    // Create an instance of the toplevel module
    TopLevel t("t");

    // Start simulation
    sc_start();

    return 0;
}
