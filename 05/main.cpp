//
// Created by jamulan on 2020-11-30.
//
#include "main.h"

int main() {
    vector<string> input = {};
    fstream inputFile;
    inputFile.open("input", ios::in);

    while (!inputFile.eof()) {
        string n;
        inputFile >> n;
        input.push_back(n);
    }

    const int MAX_ID = (127*8) + 7;
    bool seats[MAX_ID] = {};
    for(bool seat : seats) {
        seat = false;
    }

    int tmp, highestId = 0;
    Seat curr;
    for(string str : input) {
        curr = getSeat(str);
        tmp = curr.id();
        seats[tmp] = true;
        if(tmp > highestId) {
            highestId = tmp;
        }
    }
    Seat testSeat;
    int myId = -1;
    for(int i = 0; i < 128; i++) {
        for(int j = 0; j < 8; j++) {
            testSeat.row = i;
            testSeat.column = j;
            tmp = testSeat.id();
            if(seats[tmp - 1] && seats[tmp + 1] && !seats[tmp]) {
                myId = tmp;
            }
        }
    }
    cout << highestId << '\n' << myId;

    return 0;
}

Seat getSeat(string input) {
    Seat out;
    int upper = 128, lower = 0, mid = upper/2;
    int upper1 = 8, lower1 = 0, mid1 = upper1/2, j = 0;
    for(int i = 0; i < 7; i++) {
        if(input[i] == 'F') {
            upper = mid;
            mid = ((upper-lower) / 2) + lower;
        } else { // input[i] must by 'B'
            lower = mid;
            mid = ((upper-lower) / 2) + lower;
        }
        if(i < 3) {
            j = i + 7;
            if(input[j] == 'L') {
                upper1 = mid1;
                mid1 = ((upper1-lower1) / 2) + lower1;
            } else { // input[j] must be 'R'
                lower1 = mid1;
                mid1 = ((upper1-lower1) / 2) + lower1;
            }
        }
    }
    out.row = mid;
    out.column = mid1;

    return out;
}

int Seat::id() {
    return (row*8) + column;
}