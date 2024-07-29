#ifndef TRANSITION_H
#define TRANSITION_H

#include <systemc.h>

#include "place.h"

// Transition:
// TODO
template<unsigned int N = 1, unsigned int M = 1, unsigned int L = 0>
SC_MODULE(transition)
{

    sc_port<placeInterface, N, SC_ALL_BOUND> in;
    sc_port<placeInterface, M, SC_ALL_BOUND> out;
    sc_port<placeInterface, L, SC_ZERO_OR_MORE_BOUND> inhibitors;


    SC_CTOR(transition) {}

    void fire()
    {
        bool allInputHaveToken = true;
        for(int i = 0; i < N; i++){
            if(in[i]->testTokens()<1)
            {
                allInputHaveToken = false;
                break;
            }

        }
        bool allInhibitorsEmpty = true;
        for(int i = 0; i < L; i++)
        {
            if(inhibitors[i]->testTokens()>0)
            {
                allInhibitorsEmpty = false;
            }
        }

        if (allInputHaveToken && allInhibitorsEmpty)
        {
            std::cout << this->name() << ": Fired" << std::endl;

            for(int i = 0; i < N; i++)
            {
                in[i]->removeTokens();
            }
            for(int j = 0; j < M; j++)
            {
                out[j]->addTokens();
            }

        }
        else
        {
            std::cout << this->name() << ": NOT FIRED" << std::endl;
        }
    }
};

#endif // TRANSITION_H
