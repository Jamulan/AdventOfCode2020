#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    vector<int> input = {};
    fstream inputFile;
    inputFile.open("input", ios::in);

    while(!inputFile.eof()) {
        int n;
        inputFile >> n;
        input.push_back(n);
    }
    bool go = true;
    for(int i = 0; i < input.size() && go; ++i) {
        for(int j = 0; j < input.size() && go; ++j) {
            if(input[i] + input[j] == 2020 && i != j) {
                printf("answer: %d + %d = 2020, %d\n", input[i], input[j], input[i] * input[j]);
                go = false;
            }
        }
    }
    go = true;
    for(int i = 0; i < input.size() && go; ++i) {
        for(int j = 0; j < input.size() && go; ++j) {
            for(int k = 0; k < input.size() && go; ++k) {
                if(input[i] + input[j] + input[k] == 2020 && i != j && i != k && j != k) {
                    printf("answer: %d + %d + %d = 2020, %d\n", input[i], input[j], input[k], input[i] * input[j] * input[k]);
                    go = false;
                }
            }
        }
    }


    return 0;
}
