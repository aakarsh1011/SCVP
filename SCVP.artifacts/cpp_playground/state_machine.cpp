#include <iostream>

#include "state_machine.h"

void stateMachine::process()
{
    if(currentState == Start)
    {
        if(input.read() == 'G')
        {
            currentState = G;
            counter++;
        }
        else
        {
            currentState = Start;
            counter++;
        }
    }

    else if(currentState == G)
    {
        if(input.read() == 'G')
        {
            currentState = G;
            counter++;
        }
        else if(input.read() == 'A')
        {
            currentState = GA;
            counter++;
        }
        else
        {
            currentState = Start;
            counter++;
        }
    }

    else if(currentState == GA)
    {
        if(input.read() == 'G')
        {
            currentState = G;
            counter++;
        }
        else if(input.read() == 'A')
        {
            currentState = GAA;
            counter++;
        }
        else
        {
            currentState = Start;
            counter++;
        }
    }

    else if(currentState == GAA)
    {
        if(input.read() == 'G')
        {   
            currentState = GAAG;
            counter++;
            count++;
            cout << "Pattern GAAG found times: " << count  << " at: " << counter-3 << endl;
        }
        else
        {
            currentState = Start;
            counter++;
        }
    }
    else if(currentState == GAAG)
    {
        if(input.read() == 'G')
        {
            currentState = G;
            counter++;
        }
        else if (input.read() == 'A')
        {
            currentState = GA;
            counter++;
        }
        else
        {
            currentState = Start;
            counter++;
        }
    }
}