#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int licznik = 0;
    char rundyStr[5];

    printf("Podaj ile rund chcesz zagrac: ");
    scanf("%s", rundyStr);
    int rundy = atoi(rundyStr);

    char (*scores)[3] = malloc(sizeof(char[rundy][3]));

    while (rundy > 0)
    {
        char playerChoiceStr[10];
        int computerChoice;
        char playerMove;
        char computerMove;
        char result;


        printf("Wybierz:\n");
        printf("1 - Papier\n");
        printf("2 - Kamien\n");
        printf("3 - Nozyce\n");
        printf("score - Wyswietlenie wynikow\n");
        printf("Twoj wybor: ");
        scanf("%s", playerChoiceStr);


        while (strcmp(playerChoiceStr,"score") == 0)
        {
            if (licznik == 0){
                printf("Brak historii gier.\n ");
            } else {

                printf("Gracz   Komputer   Wynik\n");
                for (int i = 0; i < licznik; i++) {
                    for (int j = 0; j < 3; j++) {
                        printf(" %c         ", scores[i][j]);
                    }
                    printf("\n");
                }
            }

            printf("Wybierz:\n");
            printf("1 - Papier\n");
            printf("2 - Kamien\n");
            printf("3 - Nozyce\n");
            printf("score - Wyswietlenie wynikow \n");
            printf("Twoj wybor: ");
            scanf("%s", playerChoiceStr);
        }


        int playerChoice = atoi(playerChoiceStr);

        while (playerChoice < 1 || playerChoice > 3){
            printf("Niepoprawny wybor. Podaj ponowie.\n");
            printf("Twoj wybor: ");
            scanf("%s", playerChoiceStr);
            while (strcmp(playerChoiceStr,"score") == 0)
            {
                if (licznik == 0){
                    printf("Brak historii gier.\n ");
                } else {

                    printf("Gracz   Komputer   Wynik\n");
                    for (int i = 0; i < licznik; i++) {
                        for (int j = 0; j < 3; j++) {
                            printf(" %c         ", scores[i][j]);
                        }
                        printf("\n");
                    }
                }

                printf("Wybierz:\n");
                printf("1 - Papier\n");
                printf("2 - Kamien\n");
                printf("3 - Nozyce\n");
                printf("score - Wyswietlenie wynikow \n");
                printf("Twoj wybor: ");
                scanf("%s", playerChoiceStr);
            }
            playerChoice = atoi(playerChoiceStr);
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


        scores[licznik][0] = playerMove;
        scores[licznik][1] = computerMove;
        scores[licznik][2] = result;
        licznik ++;
        rundy --;
    }

    return 0;
}
