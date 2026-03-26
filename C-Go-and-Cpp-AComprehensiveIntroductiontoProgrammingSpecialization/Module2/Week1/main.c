#include <stdio.h>

enum weekday {
    saturday, sunday, monday, tuesday, wednesday, thursday, friday
};

void printDay(enum weekday d) {
    switch (d) {
        case saturday:
            printf("saturday");
            break;

        case sunday:
            printf("sunday");
            break;
        case monday:
            printf("monday");
            break;
        case tuesday:
            printf("tuesday");
            break;
        case wednesday:
            printf("wednesday");
            break;
        case thursday:
            printf("thursday");
            break;
        case friday:
            printf("friday");
            break;
        default:
            printf("ERROR");
            break;
    }



}
enum weekday next_day(enum weekday d){
    return (d+1%7);
}

int main(){
    printDay(6);
    printf("\n");
    printDay(next_day(67));
    printf("\n");
    printf("zaboora");
    return 1;
}
