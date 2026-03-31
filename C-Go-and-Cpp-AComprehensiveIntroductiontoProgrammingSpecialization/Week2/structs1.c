//
// Created by khaled on 28.03.26.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int re;
    int im;
}complex;
char sign(int number){
    if(number<0){
        return '-';
    }
    return '+';
}

void printComplex(complex number ,int first){
    int re = number.re;
    int im = number.im;
    if(re ==0 && im ==0){

        if(first){printf("0 ");return;}

        printf("+ 0 ");return;
    }

    if(re !=0){
        if(first){
            if(re > 0){printf("%d " , re);}
            else{printf("%c %d ",sign(re),abs(re));}
        }
        else{printf("%c %d ", sign(re), abs(re));}
        first = 0;
    }

    if(im!=0){
        if(first){
            if(im ==-1){ printf("%ci ", sign(im));return;}
            else if(im == 1){ printf("i ");}
            else if(im > 0){printf("%di " , im);return;}

            else{printf("%c %di ",sign(im),abs(im));return;}
        }

        else{
            if(abs(im)==1 ){printf("%c i ",sign(im));return;}
            printf("%c %di ", sign(im), abs(im));return;
        }
    }

}


complex addComplex(complex num1, complex num2){
    complex result = {num1.re + num2.re, num1.im + num2.im};

    return result;

}
void printAndAddComplex(complex num1, complex num2){
    printComplex(num1,1);
    printComplex(num2,0);
    printf("= ");
    printComplex(addComplex(num1,num2),1);
    printf("\n");
}


int main(){

    complex ali = {6,7};
    complex baba = {6,9};
    int end = 0;
    while(end !=1){
        scanf("%d %d %d %d" , &ali.re , &ali.im , &baba.re, &baba.im );
        if(ali.re == 67 && ali.im == 67){
            end = 1;
            break;
        }
        printAndAddComplex(ali,baba);
    }
}

