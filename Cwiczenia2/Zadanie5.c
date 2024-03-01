#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char imie[50];
    char nazwisko[50];
    char numer_tel[10];

} Contact;

void DodajKontakt(Contact *tablica, int *p_ilosc_kontaktow){

    if (*p_ilosc_kontaktow >= 100){
        printf("Lista jest pelna.");
        return;
    }

    printf("Podaj imie:");
    scanf("%s",tablica[*p_ilosc_kontaktow].imie);
    printf("Podaj nazwisko:");
    scanf("%s",tablica[*p_ilosc_kontaktow].nazwisko);
    printf("Podaj numer telefonu:");
    scanf("%s",tablica[*p_ilosc_kontaktow].numer_tel);
    (*p_ilosc_kontaktow)++;
    printf("Dodano uzytkownika.\n");


}

void SzukajKontaktu(Contact *tablica,int *ilosc_kontaktow){
    char szukane_nazwisko[50];
    printf("Podaj szukane nazwisko:");
    scanf("%s",szukane_nazwisko);
    int znaleziono = 0;
    for (int i = 0;i < *ilosc_kontaktow; i++){
        if (strcmp(tablica[i].nazwisko,szukane_nazwisko) == 0){
            znaleziono = 1;
            printf("[ZNALEZIONO DANE] \n");
            printf("Imie: %s \n",tablica[i].imie);
            printf("Nazwisko: %s \n",tablica[i].nazwisko);
            printf("Numer: %s \n", tablica[i].numer_tel);
        }
    }

    if (!znaleziono){
        printf("Nie znaleziono danych. \n");
    }

}

void UsunKontakt(Contact *tablica, int *ilosc_kontaktow){
    char szukane_nazwisko[50];
    printf("Podaj nazwisko do usuniecia:");
    scanf("%s",szukane_nazwisko);
    int szukane_id = -1;
    for (int i = 0;i < *ilosc_kontaktow; i++){
        if (strcmp(tablica[i].nazwisko,szukane_nazwisko) == 0){
            szukane_id = i;
            break;
        }
    }

    if (szukane_id >= 0) {
        for (int i = szukane_id; i < *ilosc_kontaktow - 1; i++) {
            tablica[i] = tablica[i + 1];
        }
        (*ilosc_kontaktow)--;
        printf("Usunieto kontakt. \n");
    } else {
        printf("Nie znaleziono kontaktu. \n");
    }

}

void WypiszWszystko(Contact *tablica, int *rozmiar){
    printf("[KSIAZKA ADRESOWA] \n");
    for(int i = 0; i < *rozmiar; i++){
        printf("\n");
        printf("ID: %d \n",i+1);
        printf("Imie: %s \n",tablica[i].imie);
        printf("Nazwisko: %s \n",tablica[i].nazwisko);
        printf("Numer: %s \n", tablica[i].numer_tel);
    }
}

int main(){

    Contact contacts[100] = {
            {"Adam","Kubica","123456789"},
            {"Robert", "Malysz","987654321"},
            {"Mariusz","Mickiewicz","456789321"},
            {"Jan","Slowacki","321654987"}
    };

    Contact *p_contacts = &contacts;
    int ilosc_kontaktow = 4; // początkowa ilośc
    int *p_ilosc_kontaktow = &ilosc_kontaktow;
    char opcjaStr[2];
    int opcja = -1;


    while (opcja != 5) {
        printf("[  MENU  ]\n");
        printf("1. Dodanie nowego kontaktu. \n");
        printf("2. Wyszukanie kontaktu po nazwisku. \n");
        printf("3. Usuniecie wybranego kontaktu. \n");
        printf("4. Wyswietlenie wszystkich kontaktow. \n");
        printf("5. Wyjscie. \n");
        printf("Wybierz numer: ");
        scanf("%1s",opcjaStr);
        opcja = atoi(opcjaStr);

        switch (opcja) {

            case 1:
                DodajKontakt(p_contacts, p_ilosc_kontaktow);
                break;
            case 2:
                SzukajKontaktu(p_contacts, p_ilosc_kontaktow);
                break;
            case 3:
                UsunKontakt(p_contacts, p_ilosc_kontaktow);
                break;
            case 4:
                WypiszWszystko(p_contacts, p_ilosc_kontaktow);
                break;
            case 5:
                printf("Do zobaczenia.");
                break;
            default:
                printf("Podano nieprawdilowy numer. Wybierz ponownie. \n");
                break;
        }

    }

    return 0;

}