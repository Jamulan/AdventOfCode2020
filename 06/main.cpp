//
// Created by jamulan on 2020-11-30.
//
#include "main.h"

int main() {
    fstream inputFile;
    inputFile.open("input", ios::in);

    int total = 0, totalALL = 0;
    bool go = true;
    while (!inputFile.eof()) {
        go = true;
        bool answers[26] = {};
        bool answersALL[26] = {}; // -1 = invalid, 0 = false, 1 = true
        for(int i = 0; i < 26; i++) { answersALL[i] = true; }
        while(go) {
            string n;
            inputFile >> n;


            bool thisAnswers[26] = {};

            for(char c : n) {
                for(int i = 0; i < alphabeta.size(); i++) {
                    if(c == alphabeta[i]) {
                        thisAnswers[i] = true;
                    }
                }
            }
            for(int i = 0; i < 26; i++) {
                answers[i] = answers[i] || thisAnswers[i];
                answersALL[i] = answersALL[i] && thisAnswers[i];
            }

            if(inputFile.peek() == '\n') {
                inputFile.get();
                if(inputFile.peek() == '\n') {
                    inputFile.get();
                    go = false;
                }
            }
            if(inputFile.eof()) {
                go = false;
            }
        }
        int currCount = 0, currCountALL = 0;
        for(bool b : answers) {
            if(b) {
                currCount++;
            }
        }
        for(bool b : answersALL) {
            if(b) {
                currCountALL++;
            }
        }
        total = total + currCount;
        totalALL = totalALL + currCountALL;
    }
    cout << total << '\n' << totalALL << '\n';

    return 0;
}
