//
// Created by khaled on 29.03.26.
//
#include <stdio.h>
#include <ctype.h>
#define MAX_LEN 1000
#define EMPTY (-1)
#define FULL (MAX_LEN-1)


typedef struct{
    char s[MAX_LEN];
    int top;
}stack;



void reset(stack *stack ){stack->top=EMPTY;};
char pop(stack *stack){ return(stack->s[stack->top--]);} //gives the top of the stack as output then decrements the top by 1
char top(const stack *stack){return stack->s[stack->top];}
int isEmpty(stack *stack){return stack->top==EMPTY;}
int isFull(stack *stack){return stack->top == FULL;}

void push(char newElement, stack *stack1){
    if(!isFull(stack1)){
        stack1->top++;
        stack1->s[stack1->top] = newElement;
    }
    else{printf("error,stack overflow");}

}

int main(){
    stack stack_of_char;
    char *str = "i am otto am i";
    char str_back[20];
    int i = 0;
    reset(&stack_of_char);
    printf("original is: %s\n",str);
    while (str[i] != '\0'){
        printf("%c\n",str[i]);
        push(str[i++],&stack_of_char);
    }
    i=0;
    while(!isEmpty(&stack_of_char) && i<20){
        str_back[i++] = pop(&stack_of_char);
    }
    printf("reverse is:  %s\n", str_back);
    printf("\n\n");



}