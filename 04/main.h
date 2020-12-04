//
// Created by jamulan on 2020-11-30.
//

#ifndef ADVENTOFCODE2020_MAIN_H
#define ADVENTOFCODE2020_MAIN_H
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

string hexPoss = "0123456789abcdef";
string decPoss = "0123456789";
vector<string> eyeColours = {
        "amb",
        "blu",
        "brn",
        "gry",
        "grn",
        "hzl",
        "oth"
};

struct Port {
    string byr;
    string iyr;
    string eyr;
    string hgt;
    string hcl;
    string ecl;
    string pid;
};

int isValidOne(Port port); // returns 1 if valid, returns 0 if not valid
int isValidTwo(Port port); // returns 1 if valid, returns 0 if not valid

#endif //ADVENTOFCODE2020_MAIN_H
