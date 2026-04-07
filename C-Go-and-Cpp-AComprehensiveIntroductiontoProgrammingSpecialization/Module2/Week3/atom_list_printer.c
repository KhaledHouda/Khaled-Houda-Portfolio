//
// Created by khaled on 02.04.26.
//This project goes somewhat beyond what was required, it allows the user to input a 2 digit list size in addition to, as required, allowing the entering of infos for a custom atom.
//option 2 was chosen as it is more concrete but also more of a challenge

#ifdef _WIN32
#include <windows.h>
    #define PLATFORM_SLEEP(ms) Sleep(ms)
#else
#include <unistd.h>
#define PLATFORM_SLEEP(ms) usleep(ms * 1000)  //i included cross platform logic for my timers for more satisfying UI
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>



typedef struct{
    char* name;
    char* symbol;
    float weight;
}Atom;

typedef struct List{ //atom list custom type
    Atom data;
    struct List* next;
}List;

List* create_list(Atom data){ //creates a list of atoms
    List* head = malloc(sizeof(List));
    head->data = data;
    head->next = NULL;
    return head;
}


List* add_atom_to_list(List* head, char* name, char* symbol, float weight){
    Atom atom;
    atom.name = strdup(name);
    atom.symbol = strdup(symbol);
    atom.weight = weight;
    List* newElement = malloc(sizeof(List));
    if(newElement==NULL){return NULL;}
    newElement->data = atom;
    newElement->next = head;
    head = newElement;
    return head;
}

List* make_atom_list(int length){ //logic for parameter input by the user plus assigning the info to each element in the list
    List *head = NULL;
    char name[21];
    char symbol[3];
    float weight = 0;
    printf("====================\n");
    for(int i=0; i <length ; i++){
        printf("please input the data for the first 10 elements of the periodic table.\n");
        printf("we are at element %d\n", i+1);
        printf("name: ");
        scanf(" %20s", name );
        printf("\nsymbol: ");
        scanf(" %2s", symbol );
        printf("\nweight:");
        if (scanf(" %f", &weight) != 1) {
            printf("Invalid input! Please enter a numeric weight.\n");
            // Standard trick to clear the input buffer:
            while (getchar() != '\n');
            i--; // Don't count this failed attempt
            continue;
        }
        printf("====================\n");
        head  = add_atom_to_list(head, name, symbol, weight);
    }
    return head;

}

void printAtomList(List* list) {
    List *head = list;
    printf("printing Atom List.");
    fflush(stdout);
    PLATFORM_SLEEP(200); //pause purely for aesthetics plus as a chance to learn a little about timing functions
    fflush(stdout);
    printf(".");
    fflush(stdout);
    PLATFORM_SLEEP(200);
    printf("..\n\n");
    int counter = 0;
    printf("\n%-4s | %-12s | %-5s | %-10s\n", "ID", "Element", "Sym", "Weight");
    printf("------------------------------------------\n");
    while(list != NULL) {
        const Atom currentAtom = list->data;
        counter++;
        printf("| %-2d | %-12s | %-3s | %8.4f |\n", counter, currentAtom.name, currentAtom.symbol, currentAtom.weight);
        list = list->next;
    }
}
void free_atom_list(List* head){
    while(head!=NULL){
    List* tempHead = head->next;
    Atom* current_atom = &(head->data);
    free(current_atom->name);
    free(current_atom->symbol);
    free(head);
    head = tempHead;
    }


}


int main(){
    int list_size = 2;
    //printf("type your 2 digit atom list size:"); //i hardcoded list size 10 but the code and logic for custom sizes is available
    //scanf("%3d",&list_size);

    if(list_size>99){
        printf("\nERROR: LIST SIZE TOO BIG, ABORTING PROGRAM");
        return 0;
    }
    printf("\n");
    List* atomList = make_atom_list(list_size);
    printAtomList(atomList);
    free_atom_list(atomList);
    atomList=NULL;
}