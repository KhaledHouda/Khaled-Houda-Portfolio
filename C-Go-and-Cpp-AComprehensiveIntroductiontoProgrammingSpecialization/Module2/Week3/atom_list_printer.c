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
Atom* create_Atom( char* name, char* symbol,const float* weight){ //creates an atom and returns a pointer to said atom
    Atom* at = malloc(sizeof(Atom) );
    if(at==NULL){return NULL;}

    at->name = strdup(name); at->weight = *weight; at->symbol = strdup(symbol);

    if(at->name == NULL || at->symbol == NULL){ free(at->name);free(at->symbol);free(at);return NULL;}

    return at;
}
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

List* add_to_front(Atom data, List* h){ //LIFO style list adding elements to the beginning of the list rather than the end, bypasses the need for a tail iterator as we are always at the beginning of the list
    List *head = create_list(data);
    head->next = h;
    return head;
}



List* make_atom_list(int length){ //logic for parameter input by the user plus assigning the info to each element in the list
    List *head = NULL;
    Atom* temp_atom_ptr = NULL;
    char name[21];
    char symbol[3];
    float weight = 0;
    printf("====================\n");
    for(int i=0; i <length ; i++){
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
        temp_atom_ptr = create_Atom(name, symbol, &weight);
        head  = add_to_front( *temp_atom_ptr, head);
        free(temp_atom_ptr);
    }
    return head;

}

void printAtomList(List* list , int list_size) {
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
        const Atom* currentAtom = &(list->data);
        counter++;
        printf("| %-2d | %-12s | %-3s | %8.4f |\n", counter, currentAtom->name, currentAtom->symbol, currentAtom->weight);
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
    int list_size = 10;
    //printf("type your 2 digit atom list size:"); //i hardcoded list size 10 but the code and logic for custom sizes is available
    //scanf("%3d",&list_size);

    if(list_size>99){
        printf("\nERROR: LIST SIZE TOO BIG, ABORTING PROGRAM");
        return 0;
    }
    printf("\n");
    List* atomList = make_atom_list(list_size);
    printAtomList(atomList,list_size);
    free_atom_list(atomList);
    atomList=NULL;
}