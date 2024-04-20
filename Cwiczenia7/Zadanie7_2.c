#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARS 160

int main(){
    const char *filename = "input2.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Nie mozna otworzyc pliku.\n");
        exit(EXIT_FAILURE);
    }

    int sum = 0;
    int min_sum = 0;
    char line[MAX_CHARS];
    int max_red = 12;
    int max_green = 13;
    int max_blue = 14;



    while (fgets(line, sizeof(line), file)) {
        int actual_line_len = 0;
        int flag = 0;

        int min_red = 0;
        int min_green = 0;
        int min_blue = 0;


        // sprawdzanie rzeczywistej dlugosci linii
        for (int i = 0; i < strlen(line); i++){
            if(line[i] != NULL){
                actual_line_len++;
            }
        }

        char c1 = line[5];
        char c2 = line[6];
        char c3 = line[7];
        int game_number;

        if (isdigit(c3)){
            game_number = (c1 - '0') * 100 + (c2 - '0') * 10 + (c3 - '0');
        } else if(isdigit(c2)) {
            game_number = (c1 - '0') * 10 + (c2 - '0');
        } else {
            game_number = (c1 - '0');
        }

        int number;
        for (int i = 8; i < actual_line_len; i++) {

            if (isdigit(line[i])) {
                if (isdigit(line[i + 1])) {
                    number = (line[i] - '0') * 10 + (line[i + 1] - '0');
                    i++;
                } else {
                    number = line[i] - '0';
                }
            }

                if (strncmp(&line[i], "red", 3) == 0) {
                    if (number > max_red) {
                        flag = 1;
                    }
                    if (number > min_red){
                        min_red = number;
                    }
                }

                if (strncmp(&line[i], "green", 5) == 0) {
                    if (number > max_green) {
                        flag = 1;
                    }
                    if (number > min_green){
                        min_green = number;
                    }
                }

                if (strncmp(&line[i], "blue", 4) == 0) {
                    if (number > max_blue) {
                        flag = 1;
                    }
                    if (number > min_blue){
                        min_blue = number;
                    }
                }

        }
        printf("red %d, green %d, blue %d \n", min_red, min_green, min_blue);
        min_sum += (min_red * min_green * min_blue);

        if (flag == 0){
            sum += game_number;
        }
    }

    fclose(file);

    printf("Suma numerow gier, ktore mozna rozegrac: %d\n",sum);
    printf("Suma mocy zestawow wymaganych do rozegrania gier: %d",min_sum);


    return 0;
}