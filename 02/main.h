//
// Created by jamulan on 2020-11-30.
//

#ifndef ADVENTOFCODE2020_MAIN_H
#define ADVENTOFCODE2020_MAIN_H

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Password {
    int min;
    int max;
    char letter;
    string word;
} dummyPassword;

int isValidPartOne(Password password); // returns 0 if not valid, returns 1 if valid
int isValidPartTwo(Password password);

#endif //ADVENTOFCODE2020_MAIN_H
