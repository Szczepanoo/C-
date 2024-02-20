#include <iostream>

int main()
{
    int grades[5][2] = { {3,4},{5,4},{2,5},{3,3},{4,2} };

    double suma_oceny_matematyka = 0;
    double suma_oceny_fizyka = 0;

    for (int i = 0; i <= 4; i++)
    {
        suma_oceny_matematyka += grades[i][0];
    }


    for (int i = 0; i <= 4; i++)
    {
        suma_oceny_fizyka += grades[i][1];
    }

    printf("Srednia ocen z matematyki: %.2f \n", suma_oceny_matematyka / 5);
    printf("Srednia ocen z matematyki: %.2f", suma_oceny_fizyka / 5);

    return 0;
}
