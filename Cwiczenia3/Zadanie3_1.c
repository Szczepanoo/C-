#include "stdio.h"
#include "stdlib.h"

int main(){
    int height;
    printf("Podaj wartosc n:");
    scanf("%d",&height);

    int **triangle = (int **)malloc(height * sizeof(int *));


    // Alokacja każdego wiersza
    for (int i = 0; i < height; i++) {
        triangle[i] = (int *)malloc((i + 1) * sizeof(int));
    }

    // Wypełnianie trójkąta
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            if(j == 0 || j == i){
                triangle[i][j] = 1;
            } else {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
    }

    // Wyświetlenie trójkąta
    for (int i = 0; i < height; i++) {
        // Wyświetlenie spacji
        for (int j = 0; j < height - i - 1; j++)
            printf(" ");

        // Wyświetlanie współczynników
        for (int j = 0; j <= i; j++)
            printf("%d ", triangle[i][j]);

        printf("\n");

    }

    free(triangle);
    return 0;


}