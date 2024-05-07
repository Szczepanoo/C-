#include <iostream>
#include <memory>
#include <cstring>
#include <fstream>

using namespace std;

int main(){

    string file_name = "input2.txt";
    ifstream file(file_name);

    if (!file.is_open()) {
        cerr << "Nie mozna otworzyc pliku." << endl;
        return 1;
    }

    int sum = 0;
    int min_sum = 0;
    string line;
    int max_red = 12;
    int max_green = 13;
    int max_blue = 14;

    while (getline(file, line)) {
        int actual_line_len = 0;
        int flag = 0;

        int min_red = 0;
        int min_green = 0;
        int min_blue = 0;


        // sprawdzanie rzeczywistej dlugosci linii
        for (int i = 0; i < line.length(); i++){
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

            if (line.substr(line[i], 3) == "red") {
                if (number > max_red) {
                    flag = 1;
                }
                if (number > min_red){
                    min_red = number;
                }
            }

            if (line.substr(line[i], 5) == "green") {
                if (number > max_green) {
                    flag = 1;
                }
                if (number > min_green){
                    min_green = number;
                }
            }

            if (line.substr(line[i], 4) == "blue") {
                if (number > max_blue) {
                    flag = 1;
                }
                if (number > min_blue){
                    min_blue = number;
                }
            }

        }

        min_sum += (min_red * min_green * min_blue);

        if (flag == 0){
            sum += game_number;
        }
    }

    file.close();

    cout << "Suma numerow gier, ktore mozna rozegrac: " << sum << endl;
    cout << "Suma mocy zestawow wymaganych do rozegrania gier: " << min_sum << endl;

    return 0;

}