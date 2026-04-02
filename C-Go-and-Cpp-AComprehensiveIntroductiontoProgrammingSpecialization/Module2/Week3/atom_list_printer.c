//
// Created by khaled on 02.04.26.
//
#include <stdlib.h>
#include <stdio.h>



typedef struct{
    char* name;
    char* symbol;
    float weight;
}Atom;
Atom* create_Atom( char* name, char* symbol,const float* weight){
    Atom* at = malloc(sizeof(Atom) );
    at->name = name; at->weight = *weight; at->symbol = symbol;
    return at;
}
typedef struct List{
    Atom data;
    struct List* next;
}List;

List* create_list(Atom data){
    List* head = malloc(sizeof(List));
    head->data = data;
    head->next = NULL;
    return head;
}

List* add_to_front(Atom data, List* h){
    List *head = create_list(data);
    head->next = h;
    return head;
}



List* make_atom_list(int length){
    List *list = malloc(sizeof(List));
    char name[21];
    char symbol[3];
    float weight = 0;

    for(int i=0; i <length ; i++){
        printf("we are at element %d\n", i);
        printf("name: ");
        scanf("%20s", name );
        printf("\nsymbol: ");
        scanf("%2s", symbol );
        printf("\nweight:");
        scanf("%f", &weight);
        printf("\n");
        add_to_front( *create_Atom(name,symbol, &weight) , list);

    }

    return list;

}



int main(){
    make_atom_list(10);


}