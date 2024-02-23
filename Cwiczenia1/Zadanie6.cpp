#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int licznik = 0;
    while (1)
    {
        char playerChoiceStr[10];
        int computerChoice;
        char playerMove;
        char computerMove;
        char result;

        char scores[10][3];

        printf("Wybierz:\n");
        printf("1 - Papier\n");
        printf("2 - Kamien\n");
        printf("3 - Nozyce\n");
        printf("score - Wyswietlenie wynikow\n");
        printf("Twoj wybor: ");
        scanf("%s", &playerChoiceStr);


        while (strcmp(playerChoiceStr,"score") == 0)
        {
            printf("Gracz   Komputer   Wynik\n");
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 3; j++) {
                    printf(" %c         ",scores[i][j]);
                }
                printf("\n");
            }

            printf("Wybierz:\n");
            printf("1 - Papier\n");
            printf("2 - Kamien\n");
            printf("3 - Nozyce\n");
            printf("score - Wyswietlenie wynikow \n");
            printf("Twoj wybor: ");
            scanf("%s", &playerChoiceStr);
        }

        int playerChoice = atoi(playerChoiceStr);



        if (playerChoice < 1 || playerChoice > 3) {
            printf("Niepoprawny wybor. Wybierz liczbe od 1 do 3.\n");
            return 1;
        }

        switch (playerChoice) {
            case 1:
                playerMove = 'P';
                break;
            case 2:
                playerMove = 'K';
                break;
            case 3:
                playerMove = 'N';
        }


        computerChoice = rand() % 3 + 1;

        switch(computerChoice) {
            case 1:
                printf("Komputer wybral Papier.\n");
                computerMove = 'P';
                break;
            case 2:
                printf("Komputer wybral Kamien.\n");
                computerMove = 'K';
                break;
            case 3:
                printf("Komputer wybral Nozyce.\n");
                computerMove = 'N';
                break;
        }

        if (playerChoice == computerChoice) {
            printf("Remis!\n");
            result = 'R';
        } else if ((playerChoice == 1 && computerChoice == 2) ||
                   (playerChoice == 2 && computerChoice == 3) ||
                   (playerChoice == 3 && computerChoice == 1)) {
            printf("Wygrales!\n");
            result = 'W';
        } else {
            printf("Przegrales!\n");
            result = 'P';
        }

        if (licznik <= 9) {
            scores[licznik][0] = playerMove;
            scores[licznik][1] = computerMove;
            scores[licznik][2] = result;
            licznik ++;
        }


    }

    return 0;
}
