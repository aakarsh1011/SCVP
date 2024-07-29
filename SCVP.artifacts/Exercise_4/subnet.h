#ifndef SUBNET_H
#define SUBNET_H

#include <systemc.h>

#include "place.h"
#include "transition.h"

// Subnet:
// TODO
template<unsigned int Win = 1, unsigned int Wout  = 2, unsigned int L = 0>
SC_MODULE(Subnet)
{
    placeChannel<Win, Wout> ACTIVE{"ACTIVE"};  

    transition<1, 1, 1> ACT{"ACT"};
    transition<1, 1, 0> RD{"RD"};
    transition<1, 1, 0> PRE{"PRE"};
    transition<1, 1, 0> WR{"WR"};

    //cONSTRUCTOR
    SC_CTOR(Subnet): 
    ACTIVE(0), ACT("ACT"), RD("RD"), PRE("PRE"), WR("WR")
    {
        // Connect transitions and places
        ACT.out(ACTIVE);
        ACT.inhibitors(ACTIVE);
        

        RD.out(ACTIVE);
        RD.in(ACTIVE);

        
        PRE.in(ACTIVE);

        WR.out(ACTIVE);
        WR.in(ACTIVE);
    };

    void fire()
    {
        ACT.fire();
        RD.fire();
        PRE.fire();
        WR.fire(); 
    };


};

#endif // SUBNET_H
