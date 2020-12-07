//
// Created by jamulan on 2020-11-30.
//
#include "main.h"

int main() {
    rules = {};
    vector<string> keys = {};
    fstream inputFile;
    inputFile.open("input", ios::in);

    while (!inputFile.eof()) {
        Rule rule;
        string n, key;
        inputFile >> key;
        if(key == "") {
            break;
        }
        inputFile >> n;
        key.append(' ' + n);
        inputFile >> n; // "bags"
        inputFile >> n; // "contain"
        bool go = true;
        while (go) {
            inputFile >> n;
            if (n == "no") {
                rule.empty = true;
                go = false;
                char test = ' ';
                do {
                    test = inputFile.get();
                } while(test != '.');
            } else {
                rule.empty = false;
                rule.innerBagNum.push_back(stoi(n));
                string value;
                inputFile >> value;
                inputFile >> n;
                value.append(' ' + n);
                rule.innerBagCol.push_back(value);
                inputFile >> n;
                go = n[n.size() - 1] == ','; // bag/bags ,/.
            }
        }
        rules[key] = rule;
        keys.push_back(key);
    }
    int numBags = 0;
    for(string key : keys) {
        if(rules[key].empty || key == "shiny gold") continue;
        checkedBags = {};
        vector<string> bags = findInnerBags(key);
        for(string s : bags) {
            if(s == "shiny gold") {
                numBags++;
                break;
            }
        }
    }
    int nestedCount = 0;
    Rule bags = findNestedCount("shiny gold", 1);
    for(int i : bags.innerBagNum) {
        nestedCount += i;
    }
    cout << numBags << '\n' << nestedCount << '\n';

    return 0;
}

Rule findNestedCount(string bag, int num) {
    if(rules[bag].empty) return {};
    Rule out;
    out.innerBagCol = rules[bag].innerBagCol;
    out.innerBagNum = {};
    for(int i : rules[bag].innerBagNum) {
        out.innerBagNum.push_back(i * num);
    }
    int i = -1;
    int end = out.innerBagCol.size();
    while(++i < end) {
        Rule findInnerOut = findNestedCount(out.innerBagCol[i], out.innerBagNum[i]);
        for(string s : findInnerOut.innerBagCol) {
            out.innerBagCol.push_back(s);
        }
        for(int j : findInnerOut.innerBagNum) {
            out.innerBagNum.push_back(j);
        }
    }
    return out;
}

vector<string> findInnerBags(string bag) {
    if(rules[bag].empty) return {};
    for(string s : checkedBags) {
        if(bag == s) return {};
    }
    checkedBags.push_back(bag);
    vector<string> out = rules[bag].innerBagCol;
    int i = -1;
    while(++i < out.size()) {
        vector<string> findInnerOut = findInnerBags(out[i]);
        for(string s : findInnerOut) {
            out.push_back(s);
        }
    }
    return out;
}
