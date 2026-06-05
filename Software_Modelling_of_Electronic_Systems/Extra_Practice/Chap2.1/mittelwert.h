#ifndef MITTELWERT_H
#define MITTELWERT_H
#include <systemc>
using namespace sc_core;

SC_MODULE(MovingAverage){
    //PORTS
    sc_in<bool> clk,reset;
    sc_in<int> xn;
    sc_in<int> yn;
    //Processes
    void regs(); //sequential logic
    void comb(); //combinatorics

    //Constructor
    SC_CTOR(MovingAverage) {
        SC_METHOD(regs);
        sensitive << clk.pos() <<reset;
        SC_METHOD(comb);
        sensitive << xn<<xn1<<xn2<<xn3,result;
    };
    private:
    sc_signal<int> xn1,xn2,xn3,result;
};

