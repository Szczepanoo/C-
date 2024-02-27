#include <stdio.h>


typedef struct{
    char imie[50];
    char nazwisko[50];
    int numer_tel[9];

} Contact;

void DodajKontakt(Contact *tablia, int rozmiar){

}

void SzukajKontaktu(Contact *tablica, char nazwisko[50]){

}

void UsunKontakt(Contact *tablica, char nazwisko[50]){

}

void WypiszWszystko(Contact *tablica, int rozmiar){
    for(int i = 0; i < rozmiar; i++){
        printf("");
    }
}

int main(){

    Contact contacts[] = {
            {"Adam","Kubica",123456789},
            {"Robert", "Małysz",987654321},
            {"Mariusz","Mickiewicz",456789321},
            {"Jan","Słowacki",321654987}
    };

    Contact *p_contact = &contacts[0];
    int rozmiar = sizeof(contacts) / sizeof(contacts[0]);




    return 0;
}