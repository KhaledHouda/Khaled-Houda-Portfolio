//quick review on pointers

#include <cstdint>
#include <cstdio>
#include <memory>
void inc_p(int* val) { *val += 1;}
void inc_ref(int& val) { val += 1;}
class C {
    int a = 0;
};
int main() {
    int a = 5;
    int* pa = &a; //this here is a pointer to a, whith &a being the address of a

    printf("a = %d; pa = 0x%p; *pa = %d\n", a, pa, *pa);

    std::uint32_t mem[] = {0x01234567, 0x89abcdef};
    printf("%08x %08x\n" , *mem , *(mem+1)); //list addresses are right next to each other and stuff
    printf("%08x %08x\n" , mem[0] , mem[1]); //list addresses are right next to each other and stuff

    //fun fact, mem[1] is same as *(mem+1) and so on for other i in mem[i]


    //we also have references
    int i = 5;
    inc_p(&i);
    printf("i = %d\n", i);
    inc_ref(i);
    printf("i = %d\n", i);

    std::unique_ptr<C> c = std::make_unique<C>(); //unique pointer, cant be copied
    //std::unique_ptr<C> d = c DOES NOT WORK ERROR

}
//Polymorphism
class IntStream {
public:
    virtual int read(){return 0;}
    virtual ~IntStream() = default;
};
class ConstStream: public IntStream {
    int c;
public:
    ConstStream(int c): c(c) {}
    int read() override {return c;} //doing a new version of the inherited read() hence override

};
