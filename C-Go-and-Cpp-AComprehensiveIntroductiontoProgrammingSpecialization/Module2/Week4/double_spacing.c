//
// Created by khaled on 4/10/26.
//


//this program double spaces input file to output file

#include<stdio.h>
#include <stdlib.h>

void print_file(FILE *fptr) {
    int c;
    rewind(fptr);
    while((c=getc(fptr))!=EOF) { //EOF is end of file getc() gets character at said position
        putc(c,stdout); //prints said character out on the screen
    }
}

void double_space(FILE *ifp, FILE *ofp) {
    int c;
    rewind(ifp);
    while((c=getc(ifp))!=EOF) { //EOF is -1 
        putc(c,ofp);
        if (c == '\n') { //everytime you see a space you add an extra space before continuing reading the file
            putc('\n',ofp);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *ifp, *ofp;

    if (argc !=3) {
        printf("need executable input and output file\n");
        exit(0);
    }
    ifp = fopen(argv[1],"r+"); //read and add writing to it
    ofp = fopen(argv[2],"w+"); //write and add reading to it
    printf("my %s file as read is \n\n", argv[1]);
    print_file(ifp);
    printf("\n\n");
    double_space(ifp,ofp);
    printf("my %s file as double space is \n\n", argv[2]);
    print_file(ofp);
    printf("\n\n");
}