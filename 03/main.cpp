//
// Created by jamulan on 2020-11-30.
//
#include "main.h"

int main() {
    vector<string> input = {};
    fstream inputFile;
    inputFile.open("input", ios::in);

    while (!inputFile.eof()) { // 0 is no tree, 1 is tree
        string n;
        inputFile >> n;
        input.push_back(n);
    }
    int slopes[5][2] = {
            {1, 1},
            {3, 1},
            {5, 1},
            {7, 1},
            {1, 2}
    };
    T prod = 1;
    for(int i = 0; i < 5; i++) {
        prod *= numTreesForSlope(slopes[i][0], slopes[i][1], input);
    }
    cout << prod;
    return 0;
}

T numTreesForSlope(int right, int down, vector<string> input) {
    T count = 0; // number of trees encountered
    int i = 0, j = 0;
    bool go = true;
    while(go) {
        if(input[j].data()[i] == '#') {
            count++;
        }
        i = (i + right) % input[j].size();
        j+=down;
        if(j >= input.size()) {
            go = false;
        }
    }
    return count;
}
