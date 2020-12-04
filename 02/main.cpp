//
// Created by jamulan on 2020-11-30.
//
#include "main.h"

int main() {
    vector<Password> input = {};
    fstream inputFile;
    inputFile.open("input", ios::in);


    int count1 = 0; // number of valid passwords
    int count2 = 0; // number of valid passwords for part two
    int i = 0;
    while (!inputFile.eof()) {
        Password password;
        inputFile >> password.min;
        inputFile >> password.letter; // to get rid of the '-'
        inputFile >> password.max;
        inputFile >> password.letter;
        inputFile >> password.word; // to get rid of the ':'
        inputFile >> password.word;
        input.push_back(password);
        count1 += isValidPartOne(password);
        count2 += isValidPartTwo(password);
        i += 1;
    }
    printf("part one: %d / %d\n", count1, i);
    printf("part two: %d / %d\n", count2, i);


    return 0;
}

int isValidPartOne(Password password) {
    int count = 0; // number of times password.letter occurs in password.word
    for(char c : password.word) {
        if(c == password.letter) {
            count++;
        }
    }
    if(count <= password.max && count >= password.min) {
        return 1;
    } else {
        return 0;
    }
}

int isValidPartTwo(Password password) {
    bool first;
    bool second;
    first = password.word.data()[password.min - 1] == password.letter;
    second = password.word.data()[password.max - 1] == password.letter;
    if(first ^ second) { // '^' is a bitwise xor operator
        return 1;
    } else {
        return 0;
    }
}

