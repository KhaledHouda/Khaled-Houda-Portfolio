#include <stdio.h>
#include <string>
using namespace std;
#include <iostream>
#include <cstdint>
#include <iomanip>
void print_mem(uint32_t* mem, uint32_t addr) {
// printf("MEM[0x%08x] = 0x%08x\n", addr, mem[addr]);
std::cout << std::hex << std::setfill('0');
std::cout << "MEM[0x" << std::setw(8) << addr << "] = 0x";
std::cout << std::setw(8) << mem[addr] << "\n";
}


int main(){
    const char* first_word = "hello";
    const char* second_word = "world";
    printf("%s %s \n", first_word, second_word);

    //OR YOU CAN USE COUT

    std::cout<<first_word <<" " << second_word;
    
    // here we got cout
    std::cout<< "\n" << "1->(" << 1 << ", " << (uint32_t)(1)<< ") -1->(" << -1 << ", " << (uint32_t)(-1) << ")\n";
    //1->(1, 1) -1->(-1, 4294967295) in usigned int -1 is the result of inverting 32 bit 1 then adding 1, giving us that huge ass number

    //we print 0.5-> then 0.5 as a float then we feed 0.5f into a setprecision which forces 3 decimal stellen on the 0.5 but removes trailing 0, unless we put a fixed before it like so fixed<<steprecision(n)
    std::cout << "0.5->(" << 0.5f << ", " << std::setprecision(3) << 0.5f<< ") 1.0/3->(" << std::setprecision(6) << 1.0/3<< ", " << std::setprecision(3) << 1.0/3 << ")\n";

    //we can override the << in order to special print our custom objects

    //here we use hexadecimal for easier recognition of bit patterns compared to binary.
    uint32_t mem[] = {1,2,3};
    print_mem(mem,0);
    print_mem(mem,1);
    return 0;
}