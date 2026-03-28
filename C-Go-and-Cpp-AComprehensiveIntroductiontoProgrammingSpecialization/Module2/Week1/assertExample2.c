
//#define NDEBUG //before assert.h, disables asserts you just disable the ndebug when you tested and are happy with the results of the asserts

#include <assert.h> //this is where we get assert from, trivial lmao
#include <stdio.h> //standard input output
#include <ctype.h>

int main(){

    double x,y;
    int stop;
    while(stop == 0){
        printf("Read in 2 floats:\n");
        scanf("%lf %lf" , &x, &y);
        assert(y!=0);
        printf("when divided x/y = %lf\n", x/y);
        if(x == 67){
            stop = 1;
        }

    }
    return 0;



}