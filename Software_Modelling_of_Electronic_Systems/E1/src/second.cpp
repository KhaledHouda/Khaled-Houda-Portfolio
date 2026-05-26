#include <stdio.h>
#include <string>
using namespace std;
#include <iostream>
#include <cstdint>
#include <iomanip>

//slide 9 till 22
// I first start with bitwise Operations

//AND like 0xabc & 0xf0f = 0xa0c
//OR like 0xbc | 0xf0f = 0xfbf
//XOR 0xabc ^ 0Xf0f = 0x5b3
//NOT ~0xf0f = 0x0f0
//LEFT SHIFT  0xf0f<<8 = 0xf00
//RIGHT SHIFT 0xf0f>>8 = 0x00f

//with these out of the way, we move to bit operations

uint32_t set_bit(uint32_t val, int bit){ //sets bit at the required position to 1 through an or operation
    return val | (1 << bit); 
}

uint32_t clear_bit(uint32_t val, int bit){ //same as set_bit just turns the bit to 0 instead
    return val & ~(1<<bit); //here we turn all the bits to 1 except the one we want to clear, which is shifted to the correct bit  
}

uint32_t toggle_bit(uint32_t val, int bit){ //takes a bit at a position and flips it
    return val ^ (1<<bit);
}

bool is_bit_set(uint32_t val, int bit){ //tells us if the bit at the position is 1 
    return (val & (1<<bit) )!=0;
}

uint8_t extract_byte(uint32_t val, int byte){
    return val >>(byte * 8) & 0xff;
}

