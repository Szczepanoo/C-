#include <stdio.h>

typedef struct{
    char imie[50];
    float ocena;

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
            {"Radek", 4.54},
            {"Jakub",4.48},
            {"Patryk",4.14},
            {"Wawrzyniec",4.44},
            {"Dawid",4.60}

    };

    Student  *p_studenci = &studenci[0];
    int rozmiar = sizeof(studenci) / sizeof(studenci[0]);
    sortujStudentow(p_studenci,rozmiar);

    for(int i = 0; i < rozmiar; i++){
        printf("Student: %s, Ocena: %.2f \n",studenci[i].imie,studenci[i].ocena);
    }

    return 0;
}