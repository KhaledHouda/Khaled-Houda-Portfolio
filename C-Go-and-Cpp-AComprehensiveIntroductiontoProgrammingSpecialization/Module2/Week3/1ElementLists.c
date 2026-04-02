//
// Created by khaled on 31.03.26.
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct list{
    int data;
    struct list *next;
}list;

int is_empty(const list *l){
    return(l==NULL);
}

void print_list(list *head, char *title){
    printf("%s\n",title);

    while(head != NULL){
        printf("%d :", head->data);
        head = head->next;
    }


}

int main(){
    list list_of_int;
    list* head = NULL;
    head = malloc(sizeof(list) );
    printf("size of list: %lu bytes \n",sizeof(list)); //%lu is unsigned long
    head->data = 5;
    head-> next = NULL;
    print_list(head, "single element list");



    return 1;
}
