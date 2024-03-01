#include <stdio.h>
#include <stdlib.h>


int main()
{
    char nStr[5];
    int suma = 0;

    printf("Podaj liczbe:");
    scanf("%s",nStr);
    int n = atoi(nStr);


    if (n < 0) {
        printf("Suma: 0");
        return 0;
    }

    
    for (int i = 1; i < n; i++) {
        if (i % 3 == 0) {
            suma += i;
            printf("%d \n", i);
        }

        else if (i % 5 == 0) {
            suma += i;
            printf("%d \n", i);
        }
    }

    printf("Suma: %d", suma);


    return 0;
}
