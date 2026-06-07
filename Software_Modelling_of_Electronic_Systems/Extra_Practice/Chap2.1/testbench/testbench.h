//
// Created by khaled on 6/7/26.
//

#ifndef CHAP2_1_TESTBENCH_H
#define CHAP2_1_TESTBENCH_H
#include <systemc>

using namespace sc_core;

struct Testbench : public sc_module {
    //Ports
    sc_in<bool> clk;
    sc_in<bool> yn;
    sc_out<bool> reset;
    sc_out<int> xn;
    //Process
    void generateStimuli();
    //Constructor
    SC_HAS_PROCESS(Testbench);
    Testbench(sc_module_name);
};

#endif //CHAP2_1_TESTBENCH_H
