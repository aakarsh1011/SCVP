#include <systemc.h>

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
        //cout << "test";
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

    // Instantiate the RS latch
    RS_Latch rs_latch("RS_Latch");
    rs_latch.R(R);
    rs_latch.S(S);
    rs_latch.Q(Q);
    rs_latch.Qn(Qn);

    // Function to print the current state
    auto print_state = [&]() {
        cout << "Time: " << sc_time_stamp() << " R: " << R.read() << " S: " << S.read()
             << " Q: " << Q.read() << " Qn: " << Qn.read() << endl;
    };

    // Simulation
    sc_start(1, SC_NS);
    R = 0; S = 0;
    sc_start(1, SC_NS);
    print_state();

    R = 0; S = 1;
    sc_start(1, SC_NS);
    print_state();

    R = 0; S = 0;
    sc_start(1, SC_NS);
    print_state();

    R = 1; S = 0;
    sc_start(1, SC_NS);
    print_state();

    R = 0; S = 0;
    sc_start(1, SC_NS);
    print_state();

    R = 1; S = 1;  // Invalid state
    sc_start(1, SC_NS);
    print_state();

    R = 0; S = 0;
    sc_start(1, SC_NS);
    print_state();

    return 0;
}
