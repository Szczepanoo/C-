#include "stdio.h"

int main(){

    int tablica[10];

    for (int i = 0; i < 20; i++) {
        tablica[i] = i;
    }
    int *intpointer = &tablica[0];
    printf("[TABLICA]\n");
    for (int i = 0; i < 10; i++){
        printf("%d\n",*intpointer);
        intpointer++;
    }

    return 0;
}