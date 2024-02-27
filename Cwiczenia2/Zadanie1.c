#include <stdio.h>

int main() {
    int zmienna = 2;
    int * pzmienna = &zmienna;
    (*pzmienna)++;
    printf("Wypisanie bezpozsrednio: %d \n",zmienna);
    printf("Wypisanie przez wskaznik: %d \n",*pzmienna);

    return 0;
}
