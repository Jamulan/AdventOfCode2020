//
// Created by jamulan on 2020-11-30.
//
#include "main.h"

int main() {
    vector<Port> input = {}; //number of required fields;
    fstream inputFile;
    inputFile.open("input", ios::in);

    bool go = true;
    while (!inputFile.eof()) {
        go = true;
        Port m;
        while(go) {
            string n;
            inputFile >> n;
            if(n.substr(0, 3) == "byr") {
                n.erase(0, 4);
                m.byr = n;
            } else if(n.substr(0, 3) == "iyr") {
                n.erase(0, 4);
                m.iyr = n;
            } else if(n.substr(0, 3) == "eyr") {
                n.erase(0, 4);
                m.eyr = n;
            } else if(n.substr(0, 3) == "hgt") {
                n.erase(0, 4);
                m.hgt = n;
            } else if(n.substr(0, 3) == "hcl") {
                n.erase(0, 4);
                m.hcl = n;
            } else if(n.substr(0, 3) == "ecl") {
                n.erase(0, 4);
                m.ecl = n;
            } else if(n.substr(0, 3) == "pid") {
                n.erase(0, 4);
                m.pid = n;
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
        input.push_back(m);
    }
    int total1 = 0;
    int total2 = 0;
    for(Port p : input) {
        total1 += isValidOne(p);
        total2 += isValidTwo(p);
    }
    cout << total1 << '\n' << total2;

    return 0;
}

int isValidOne(Port port) {
    if(!port.byr.empty() && !port.iyr.empty() && !port.eyr.empty()
    && !port.hgt.empty() && !port.hcl.empty() && !port.ecl.empty()
    && !port.pid.empty()) {
        return 1;
    }
    return 0;
}

int isValidTwo(Port port) {
    bool valid = true;
    int tmp;
    tmp = atoi(port.byr.c_str());
    valid &= port.byr.size() == 4;
    valid &= tmp <= 2002 && tmp >= 1920;

    tmp = atoi(port.iyr.c_str());
    valid &= port.iyr.size() == 4;
    valid &= tmp <= 2020 && tmp >= 2010;


    tmp = atoi(port.eyr.c_str());
    valid &= port.eyr.size() == 4;
    valid &= tmp <= 2030 && tmp >= 2020;

    if((tmp = port.hgt.find("cm")) != string::npos) {
        tmp = atoi(port.hgt.substr(0, tmp).c_str());
        valid &= tmp >= 150 && tmp <= 193;
    } else if((tmp = port.hgt.find("in")) != string::npos) {
        tmp = atoi(port.hgt.substr(0, tmp).c_str());
        valid &= tmp >= 59 && tmp <= 76;
    } else {
        valid = false;
    }

    valid &= port.hcl[0] == '#';
    valid &= port.hcl.size() == 7;
    if(!valid) return 0;
    for(char c0 : port.hcl.substr(1, 6)) {
        tmp = 0;
        for(char c : hexPoss) {
            if(c0 == c) {
                tmp = 1;
            }
        }
        valid &= tmp == 1;
    }

    tmp = 0;
    for(string colour : eyeColours) {
        if(colour == port.ecl) {
            tmp = 1;
        }
    }
    valid &= tmp == 1;

    valid &= port.pid.size() == 9;
    for(char c : port.pid) {
        tmp = 0;
        for(char c1 : decPoss) {
            if(c1 == c) {
                tmp = 1;
            }
        }
        valid &= tmp == 1;
    }


    if(valid) {
        return 1;
    } else {
        return 0;
    }
}
