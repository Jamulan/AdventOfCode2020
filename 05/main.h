//
// Created by jamulan on 2020-11-30.
//

#ifndef ADVENTOFCODE2020_MAIN_H
#define ADVENTOFCODE2020_MAIN_H
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Seat {
    int column;
    int row;
    int id();
};

Seat getSeat(string input);

#endif //ADVENTOFCODE2020_MAIN_H
