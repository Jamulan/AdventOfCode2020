//
// Created by jamulan on 2020-11-30.
//
#include "main.h"

int main() {
    vector<int> input = {};
    fstream inputFile;
    inputFile.open("input", ios::in);

    while (!inputFile.eof()) {
        int n;
        inputFile >> n;
        input.push_back(n);
    }
    printf("hello world");

    return 0;
}
