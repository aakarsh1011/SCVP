#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H
using namespace std;
#include <systemc.h>

enum base {Start, G, GA, GAA, GAAG};

SC_MODULE(stateMachine)
{
    public:
        sc_in<char> input;
        sc_in<bool> clk;

        base currentState;
        int occurrenceCounter;
        vector<int> occurrencePositions;
        int postionCounter = 0;

    void process()
    {
        if(clk.read() == 1)
        {
            switch(currentState)
            {   
                
                case Start:
                    if(input.read() == 'G')
                    {
                        currentState = G;
                    }
                    break;
                case G:
                    if(input.read() == 'A')
                    {
                        currentState = GA;
                    }
                    break;
                case GA:
                    if(input.read() == 'A')
                    {
                        currentState = GAA;
                    }
                    break;
                case GAA:
                    if(input.read() == 'G')
                    {
                        currentState = GAAG;
                        occurrenceCounter++;
                        //occurrencePositions.push_back(postionCounter);
                        cout << "FSM State is GAAG" << endl;
                        //cout << "Number of occurrences: " << occurrenceCounter << endl;
                        //cout << "Positions: ";
                        //for (const auto &position : occurrencePositions)
                        //{
                        //    cout << position << " ";
                        //}
                        //cout << endl;
                    }
                    break;
                case GAAG:
                    //cout << "FSM is in GAAG state" << endl;
                    

                    break;
                
            }

            
        }
        
    };

    SC_CTOR(stateMachine): input("input"), clk("clk"), currentState(Start)
    {
        SC_METHOD(process);
        sensitive << clk.pos();
        dont_initialize();

    }
};

#endif // STATE_MACHINE_H

