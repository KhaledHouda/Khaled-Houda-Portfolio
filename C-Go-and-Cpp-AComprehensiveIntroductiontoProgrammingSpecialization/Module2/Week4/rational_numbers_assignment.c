//
// Created by khaled on 4/11/26.
//This document demonstrates
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct rational {
    int numerator;
    int denominator;
}rational;
void fix_rational_sign(rational* number) {
    int numerator = number->numerator;
    int denominator = number->denominator;
    if (numerator < 0 && denominator < 0) {
        number->numerator = -numerator;
        number->denominator = -denominator;
        return;
    }
    if (numerator<0 && denominator>0) {
        return;
    }
    if (numerator > 0 && denominator < 0) {
        number->numerator = numerator*-1;
        number->denominator = denominator * -1;
        return;
    }
}
int find_gcd(const int nb1, const int nb2) {  //we need gcd for most operations of rational numbers
    int result = 0;
    if (nb1>nb2){result = nb1;} else{result = nb2;}
    while (result>0) {
        if (nb1%result==0 && nb2%result == 0 ) {
            break;
        }
        result--;
    }
    return result;
}
rational* simplify_rational(rational* nb) { //greatly decreases workload in operations
    if (nb->denominator == 0){fprintf(stderr, "ERROR INVALID RATIONAL NUMBER, CANT SIMPLIFY"); return nb;}
    int num = nb->numerator;
    int denom = nb->denominator;
    const int divisor = find_gcd(num,denom);
    num/=divisor;
    denom/=divisor;

    nb->numerator = num;
    nb->denominator = denom;
    fix_rational_sign(nb);
    return nb;
}

rational add_rational( rational* nb1 , rational* nb2) { //adds 2 rational numbers and outputs the result
    simplify_rational(nb1);
    simplify_rational(nb2);

    if (nb1->denominator != nb2->denominator) {
        int const numerator = nb1->numerator*nb2->denominator + nb2->numerator*nb1->denominator;
        int const denominator = nb1->denominator*nb2->denominator;

        rational result = {numerator, denominator};
        simplify_rational(&result);
        return result;
    }
    rational result = {nb1->numerator+nb2->numerator,nb1->denominator};
    simplify_rational(&result);
    return result;

}


rational multiply_rational(rational* nb1,rational* nb2) { //multiplies 2 rational numbers
    simplify_rational(nb1);
    simplify_rational(nb2);

    rational result = {nb1->numerator * nb2->numerator ,nb1->denominator * nb2->denominator};
    simplify_rational(&result);
    return result;
}
rational divide_rational( const rational* nb1, const rational* nb2) { //divides 2 rational numbers
    const int numerator = nb1->numerator*nb2->denominator;
    const int denominator = nb1->denominator*nb2->numerator;
    rational result = {numerator, denominator};
    simplify_rational(&result);
    return result;
}
void print_rational(rational* nb) {
    simplify_rational(nb);
    printf("%d / %d\n",nb->numerator,nb->denominator);
}
int get_list_size(FILE* ifp){ //from the file gets the number of fractions in said file(assuming its correctly formatted) which is the first number in the list
    int size = 0;
    if (fscanf(ifp, "%d", &size) != 1){return 0;}//takes first number of the list and assigns it to size, if 1st number not available returns 0
    return size;
}
rational rational_list_sum(rational* list, int size){
    rational sum = {list[0].numerator, list[0].denominator};

    for (int i = 1; i < size; i++) {
        sum = add_rational(&sum, &list[i]);
        simplify_rational(&sum);
    }
    return sum;
}

rational average_rational(rational list[], int size) {
    rational sum = rational_list_sum(list, size);
    rational divisor = {1,size};
    sum = multiply_rational(&sum, &divisor);
    return sum;
}




int main() {
    // 1. Open files and verify they actually exist/are writable
    FILE* ifp = fopen("input_num_list", "r");
    if (!ifp) {
        perror("ERROR: Could not open input file");
        exit(EXIT_FAILURE);
    }

    FILE* ofp = fopen("answer-hw3", "w");
    if (!ofp) {
        perror("ERROR: Could not create output file");
        fclose(ifp); // Clean up the already opened input file
        exit(EXIT_FAILURE);
    }

    // 2. Get the size and validate it
    int size = get_list_size(ifp);
    if (size <= 0) {
        fprintf(stderr, "ERROR: Invalid or zero size header in file.\n");
        fclose(ifp);
        fclose(ofp);
        exit(EXIT_FAILURE);
    }

    rational* list = malloc(size * sizeof(rational));
    if (!list) {
        fprintf(stderr, "ERROR: Memory allocation failed.\n");
        fclose(ifp);
        fclose(ofp);
        exit(EXIT_FAILURE);
    }

    int iterator = 0;
    while (iterator < size && fscanf(ifp, "%d %d", &list[iterator].numerator, &list[iterator].denominator) == 2) {
        iterator++;
    }

    // 5. Use the ACTUAL count (iterator), not the promised 'size'
    // This prevents math errors if the file has fewer numbers than it claimed.
    if (iterator > 0) {
        for (int i = 0; i < iterator; i++) {
            print_rational(&list[i]);
        }

        rational sum = rational_list_sum(list, iterator);
        rational average = average_rational(list, iterator);

        fprintf(ofp, "sum of rational numbers: %d / %d\n", sum.numerator, sum.denominator);
        fprintf(ofp, "average of rational numbers: %d / %d\n", average.numerator, average.denominator);
    } else {
        fprintf(stderr, "ERROR: No valid rational pairs found in file.\n");
    }

//memory hygiene
    free(list);
    fclose(ifp);
    fclose(ofp);

    return 0;
}