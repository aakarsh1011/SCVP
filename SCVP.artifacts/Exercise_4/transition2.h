#ifndef TRANSITION_H
#define TRANSITION_H

#include <systemc.h>
#include "place2.h"

using namespace std;


SC_MODULE(transition)
{

    sc_port<placeInterface> in;
    sc_port<placeInterface> out;

    SC_CTOR(transition){}

    void fire()
    {
        cout << this->name() << ": Fired" << endl;
    }

}