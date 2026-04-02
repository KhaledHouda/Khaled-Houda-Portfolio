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

list* create_list(int data){
    list* head = malloc(sizeof(list));
    head->data = data;
    head->next = NULL;
    return head;
}

list* add_to_front(int data, list* h){
    list *head = create_list(data);
    head->next = h;
    return head;
}

void print_list(list *head, char *title){
    printf("%s\n",title);

    while(head != NULL){
        printf("%d :", head->data);
        head = head->next;
    }


}

list* array_to_list(int array[], int size){
    list* head = create_list(array[0]);
    int i;
    for(i=1;i<size;i++ ){
        head = add_to_front(array[i], head);
    }
    return head;
}

int main(){
    int data[6] = {0,1,2,3,4,5};
    list* list = array_to_list(data, 6);
    print_list(list,"abdullah");
    return 1;
}


