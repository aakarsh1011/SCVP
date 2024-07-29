#include <systemc.h>
#include "stim.h"
#include "mon.h"

SC_MODULE(RS_Latch) {
    // Ports
    sc_in<bool> R;
    sc_in<bool> S;
    sc_out<bool> Q;
    sc_out<bool> Qn;

    // Internal signals for NOR gates
    sc_signal<bool> Q_int;
    sc_signal<bool> Qn_int;

    // NOR gate process for Q
    void nor1() {
        Q.write(!(R.read() || Qn_int.read()));
    }

    // NOR gate process for Qn
    void nor2() {
        Qn.write(!(S.read() || Q_int.read()));
    }

    // Update internal signals to outputs
    void update_internal_signals() {
        Q_int.write(Q.read());
        Qn_int.write(Qn.read());
    }

    // Constructor
    SC_CTOR(RS_Latch) {
        SC_METHOD(nor1);
        sensitive << R << Qn_int;
        SC_METHOD(nor2);
        sensitive << S << Q_int;
        SC_METHOD(update_internal_signals);
        sensitive << Q << Qn;
    }
};

int sc_main(int argc, char* argv[]) {
    // Signals
    sc_signal<bool> R;
    sc_signal<bool> S;
    sc_signal<bool> Q;
    sc_signal<bool> Qn;
    sc_clock clock("Clk", 10, SC_NS, 0.5);

    // Stimulus instance
    stim Stim1("stimulus");
    Stim1.A(S);
    Stim1.B(R);
    Stim1.Clk(clock);

    // Instantiate the RS latch
    RS_Latch rs_latch("RS_Latch");
    rs_latch.R(R);
    rs_latch.S(S);
    rs_latch.Q(Q);
    rs_latch.Qn(Qn);

    // Monitor instance
    Monitor mon("Monitor");
    mon.S(S);
    mon.R(R);
    mon.Q(Q);
    mon.Q_bar(Qn);
    mon.Clk(clock);

    // Start simulation
    sc_start(100, SC_NS);

    return 0;
}
