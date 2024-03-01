#include <stdio.h>

typedef struct{
    char imie[50];
    double ocena;

} Student;

void sortujStudentow(Student *tablica, int rozmiar) {
    int i, j;
    Student temp;

    for (i = 0; i < rozmiar - 1; i++) {
        for (j = 0; j < rozmiar - 1 - i; j++) {
            if (tablica[j].ocena < tablica[j + 1].ocena) {
                temp = tablica[j];
                tablica[j] = tablica[j + 1];
                tablica[j + 1] = temp;
            }
        }
    }
}



int main(){
    Student studenci[] = {
            {"Adam", 4.07}, {"Bartosz", 3.89}, {"Igor", 4.64}, {"Janusz", 4.95}, {"Eryk", 5.28},
            {"Filip", 4.76}, {"Cezary", 3.59}, {"Hubert", 4.23}, {"Dominik", 4.97}, {"Grzegorz", 5.75},
            {"Adam", 4.13}, {"Bartosz", 4.40}, {"Igor", 5.11}, {"Janusz", 4.90}, {"Eryk", 5.03},
            {"Filip", 5.65}, {"Cezary", 3.86}, {"Hubert", 4.77}, {"Dominik", 4.45}, {"Grzegorz", 4.32},
            {"Adam", 4.60}, {"Bartosz", 4.72}, {"Igor", 5.34}, {"Janusz", 4.68}, {"Eryk", 4.21},
            {"Filip", 5.19}, {"Cezary", 4.57}, {"Hubert", 4.84}, {"Dominik", 5.02}, {"Grzegorz", 4.99},
            {"Adam", 4.05}, {"Bartosz", 4.17}, {"Igor", 4.93}, {"Janusz", 5.10}, {"Eryk", 4.40},
            {"Filip", 5.36}, {"Cezary", 4.75}, {"Hubert", 4.68}, {"Dominik", 4.80}, {"Grzegorz", 5.45},
            {"Adam", 4.24}, {"Bartosz", 4.61}, {"Igor", 5.03}, {"Janusz", 4.55}, {"Eryk", 4.87},
            {"Filip", 5.12}, {"Cezary", 4.29}, {"Hubert", 4.94}, {"Dominik", 4.33}, {"Grzegorz", 4.70},
            {"Adam", 4.78}, {"Bartosz", 5.01}, {"Igor", 4.92}, {"Janusz", 5.20}, {"Eryk", 5.08},
            {"Filip", 4.90}, {"Cezary", 4.56}, {"Hubert", 5.15}, {"Dominik", 5.07}, {"Grzegorz", 5.29},
            {"Adam", 4.33}, {"Bartosz", 4.81}, {"Igor", 5.23}, {"Janusz", 4.62}, {"Eryk", 5.05},
            {"Filip", 5.21}, {"Cezary", 4.44}, {"Hubert", 4.90}, {"Dominik", 4.75}, {"Grzegorz", 5.12},
            {"Adam", 4.17}, {"Bartosz", 4.58}, {"Igor", 4.97}, {"Janusz", 5.18}, {"Eryk", 4.96},
            {"Filip", 5.06}, {"Cezary", 4.66}, {"Hubert", 4.89}, {"Dominik", 4.82}, {"Grzegorz", 5.33},
            {"Adam", 4.39}, {"Bartosz", 4.69}, {"Igor", 5.07}, {"Janusz", 5.15}, {"Eryk", 4.75},
            {"Filip", 5.27}, {"Cezary", 4.80}, {"Hubert", 4.98}, {"Dominik", 4.91}, {"Grzegorz", 5.17}
    };
    Student  *p_studenci = &studenci[0];
    int rozmiar = sizeof(studenci) / sizeof(studenci[0]);
    sortujStudentow(p_studenci,rozmiar);

    for(int i = 0; i < rozmiar; i++){
        printf("Student: %-10s Ocena: %.2f \n",studenci[i].imie,studenci[i].ocena);
    }

    return 0;
}