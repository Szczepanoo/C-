#include "stdio.h"

union Unia {
    int theInt;
    float theFloat;
    char theChar;
};


int main(){

    union Unia parts;

    parts.theInt = 1;
    printf("Wartosc zmiennej theInt: %d\n",parts.theInt);

    parts.theFloat = 1.2;
    printf("Wartosc zmiennej theFloat: %.2f\n",parts.theFloat);

    parts.theChar = 'C';
    printf("Wartosc zmiennej theChar: %c\n",parts.theChar);




    return 0;
}