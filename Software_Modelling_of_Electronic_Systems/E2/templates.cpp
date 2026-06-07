#include <functional>
//Function Template
//concrete version is made at compilation
template<int N> int pow(int base) {
    int res = 1;
    for(int i = 0; i < N; i++) {
        res *= base;
    }
    return res;
}//for N=3 pow<3>(5) is generated, giving us the correct power for our base

template<typename T>
class Container {
    T t;
}; //for containers where you dont want to write one for every type because there are so many

//Functions Pointer
//allows function as a parameter or attribute

template<typename T>
void sort(T* data, int(*cmp)(T const&, T const&), int N){} //ugly C way but lightweight and no overhead on runtime
// mandatory parenthesis around *cmp, to make sure it is interpreted as the pointer *cmp itself being the variable, and taking arguments (T const& , T const&)


//C++ std::function
template<typename T>
void sort(T* data, std::function<int(T const&, T const&)> cmp, int N){}