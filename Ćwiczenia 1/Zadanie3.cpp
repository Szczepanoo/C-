#include <iostream>

int main()
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for (int i = 0; i <= 9; i++) {
        int silnia = 1;
        for (int j = array[i]; j >= 1; j--) {

            silnia = silnia * j;

        }
        printf("%d\n", silnia);
    }

    return 0;


}
