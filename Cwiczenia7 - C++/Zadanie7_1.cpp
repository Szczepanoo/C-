#include <iostream>
#include <memory>
#include <cstring>
#include <fstream>

using namespace std;

int wordToNumber(char * word){
    if (strcmp(word, "zero") == 0) return 0;
    if (strcmp(word, "one") == 0) return 1;
    if (strcmp(word, "two") == 0) return 2;
    if (strcmp(word, "three") == 0) return 3;
    if (strcmp(word, "four") == 0) return 4;
    if (strcmp(word, "five") == 0) return 5;
    if (strcmp(word, "six") == 0) return 6;
    if (strcmp(word, "seven") == 0) return 7;
    if (strcmp(word, "eight") == 0) return 8;
    if (strcmp(word, "nine") == 0) return 9;
    return -1; // -1 w przypadku braku dopasowania
}

int calculateEnergySum2(const char *filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Nie mozna otworzyc pliku." << endl;
        return 1;
    }
    string line;

    char * words[] = {"zero","one", "two", "three" ,"four", "five" ,"six" ,"seven", "eight", "nine"};

    int sum = 0;

    while (getline(file, line)) {

        int number_front = -1;
        int number_back = -1;
        int actual_line_len = 0;

        for (int i = 0; i < line.length(); i++){
            if(line[i] != NULL){
                actual_line_len++;
            }
        }

        // sprawdzanie od poczatku
        for (int i = 0; i < actual_line_len; i++) {
            if (isdigit(line[i])) {
                number_front = line[i] - '0';
                break;
            } else {
                for (int j = 0; j < 10; j++) {
                    if (line.substr(i, strlen(words[j])) == words[j]) {
                        number_front = wordToNumber(words[j]);
                        break;
                    }
                }
                if (number_front != -1) {
                    break;
                }

            }
        }

        // sprawdzanie od konca
        for (int i = actual_line_len; i >= 0; i--) {
            if (isdigit(line[i])) {
                number_back = line[i] - '0';
                break;
            } else {
                for (int j = 0; j < 10; j++) {
                    if (line.substr(i, strlen(words[j])) == words[j]) {
                        number_back = wordToNumber(words[j]);
                        break;
                    }
                }
            }
            if (number_back != -1) {
                break;
            }

        }
        sum += (number_front * 10) + number_back;

    }

    file.close();
    return sum;

}

int calculateEnergySum1(const char *filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Nie mozna otworzyc pliku." << endl;
        return 1;
    }
    string line;

    int sum = 0;

    while (getline(file, line)) {

        int number_front = -1;
        int number_back = -1;
        int actual_line_len = 0;

        for (int i = 0; i < line.length(); i++){
            if(line[i] != NULL){
                actual_line_len++;
            }
        }

        // sprawdzanie od poczatku
        for (int i = 0; i < actual_line_len; i++) {
            if (isdigit(line[i])) {
                number_front = line[i] - '0';
                break;
            }
        }

        // sprawdzanie od konca
        for (int i = actual_line_len; i >= 0; i--) {
            if (isdigit(line[i])) {
                number_back = line[i] - '0';
                break;
            }
        }

        sum += (number_front * 10) + number_back;

    }

    file.close();
    return sum;

}

int main(){
    const char * file_name = "input.txt";
    cout << "I Suma wartosci energetycznych: " << calculateEnergySum1(file_name) << endl;
    cout << "II Suma wartosci energetycznych: " << calculateEnergySum2(file_name) << endl;

}