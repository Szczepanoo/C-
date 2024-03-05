#include "stdio.h"
#include "stdlib.h"

int main(){
    int rows;
    int cols;
    printf("Podaj liczbe wierszy(rows): ");
    scanf("%d",&rows);

    printf("Podaj liczbe kolumn(cols): ");
    scanf("%d",&cols);


    int **matrix = (int **)malloc(rows * sizeof(int *));
    printf("\n");

    // Alokacja każdego wiersza
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Wypełnienie i wyświetlenie
    for (int i = 0; i < rows; i ++){
        for (int j = 0;j< cols;j++){
            matrix[i][j] = (rand() % 100);
            printf("%2d ",matrix[i][j]);
        }
        printf("\n");
    }

    free(matrix);
    return 0;
}