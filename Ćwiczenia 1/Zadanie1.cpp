#include <stdio.h>

int main() {
    char imie[50];

    printf("Podaj swoje imie: ");
    scanf_s("%s", imie, sizeof(imie));

    printf("Witaj, %s\n", imie);

    return 0;
}
