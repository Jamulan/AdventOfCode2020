//
// Created by jamulan on 2020-11-30.
//

#ifndef ADVENTOFCODE2020_MAIN_H
#define ADVENTOFCODE2020_MAIN_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

struct Rule {
    vector<int> innerBagNum; // parallel
    vector<string> innerBagCol; // parallel
    bool empty;
};

unordered_map<string, Rule> rules;
vector<string> checkedBags;

vector<string> findInnerBags(string bag);

#endif //ADVENTOFCODE2020_MAIN_H
