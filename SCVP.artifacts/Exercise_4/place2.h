#ifndef PLACE_H
#define PLACE_H

#include <systemc.h>

using namespace std;


class placeInterface: public sc_interface
{
    virtual void addTokens(unsigned int n) = 0;
    virtual void removeTokens(unsigned int n) = 0;
    virtual unsigned int testTokens() = 0;

};

class placeChannel: public placeInterface
{
    private:
        unsigned int tokens;

    public:
        placeChannel(unsigned int initialTokens): tokens(initialTokens)
        {
        };

    void addTokens(){
        tokens = tokens + n;
    };
    void removeTokens(){
        tokens = tokens - n;
    };
    void testTokens(){
        return tokens;
    };
};


#endif