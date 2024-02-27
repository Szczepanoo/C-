#include <stdio.h>

void modyfikuj(float *pliczba){
    *pliczba = (*pliczba) * 2;
}

int main() {
    float liczba = 1.3;
    float *pliczba = &liczba;
    modyfikuj(pliczba);
    printf("Liczba po modyfikacji: %.2f", liczba);

    return 0;

}
