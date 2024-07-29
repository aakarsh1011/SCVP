#include <systemc.h>
#include <queue>
using namespace std;

// interface

template <class T>
class simpleFIFOinterface : public sc_interface
{
    public:
        virtual T read() = 0;
        virtual void write(T) = 0;
};

// channel
template <class T>
class simplefifo: public simpleFIFOinterface<T>
{
    private:
        queue<T> fifo;
        sc_event written_event;
        sc_event read_event;
        uint64_t maxSize;

    public:
        simplefifo(uint64_t size=16): maxSize(size) {}

        T read(){
            if(fifo.empty() == true)
            {
                wait(written_event);
            }
            T val = fifo.front();
            fifo.pop();
            read_event.notify(SC_ZERO_TIME);
            cout << "read @ : " << sc_time_stamp() << val << endl;
            return val;

        };

        void write(T val)
        {
            if(fifo.size() == maxSize)
            {
                wait(read_event);
            };
            fifo.push(val);
            written_event.notify(SC_ZERO_TIME);
            cout << "written @ : " << sc_time_stamp() << val << endl;
        };

};

// producer
SC_MODULE(PRODUCER)
{
    public:
    sc_port<simpleFIFOinterface<int>> master;

    SC_CTOR(PRODUCER){
        SC_THREAD(process);
    }

    void process()
    {
        int counter = 0;
        while (true)
        {
            wait(1, SC_NS);
            master->write(counter++);
            cout<< "P @ "<< sc_time_stamp() << endl;
        }
        
    }

};

// consumer
SC_MODULE(CONSUMER)
{
    public:
    sc_port<simpleFIFOinterface<int>> slave;

    SC_CTOR(CONSUMER)
    {
        SC_THREAD(process)
    };

    void process()
    {
        wait(4, SC_NS);
        cout<< "C @ "<< sc_time_stamp()<< ": "  << slave->read() << endl;
    };
};

// main

// to connect everything

int sc_main(int __attribute__((unused)) argc,
            char __attribute__((unused)) *argv[])
{
    simplefifo<int> channel(5);
    PRODUCER P1("p1");
    CONSUMER C1("c1");

    P1.master(channel);
    C1.slave(channel);

    sc_start(100, SC_NS);


    return 0;
};
