//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/3/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

const int MAX = 5000;

int N;
string roman[MAX];

int main() {
    freopen("romans.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    //cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < 4; i ++) {
        for (int j = 1; j <= i; j ++) {
            roman[i] += 'I';
        }
    }
    roman[4] = "IV";
    for (int i = 5; i < 9; i ++) {
        roman[i] = "V";
        for (int j = 6; j <= i; j ++) {
            roman[i] += 'I';
        }
    }
    roman[9] = "IX";
    for (int i = 10; i < 40; i ++) {
        for (int j = 1; j <= i / 10; j ++) {
            roman[i] += 'X';
        }
        roman[i] += roman[i % 10];
    }
    for (int i = 40; i < 50; i ++) {
        roman[i] = "XL";
        roman[i] += roman[i - 40];
    }
    for (int i = 50; i < 90; i ++) {
        roman[i] = "L";
        roman[i] += roman[i - 50];
    }
    for (int i = 90; i < 100; i ++) {
        roman[i] = "XC";
        roman[i] += roman[i - 90];
    }
    for (int i = 100; i < 400; i ++) {
        for (int j = 1; j <= i / 100; j ++) {
            roman[i] += 'C';
        }
        roman[i] += roman[i % 100];
    }
    for (int i = 400; i < 500; i ++) {
        roman[i] = "CD";
        roman[i] += roman[i % 100];
    }
    for (int i = 500; i < 900; i ++) {
        roman[i] = "D";
        roman[i] += roman[i - 500];
    }
    for (int i = 900; i < 1000; i ++) {
        roman[i] = "CM";
        roman[i] += roman[i - 900];
    }
    for (int i = 1000; i < 5000; i ++) {
        for (int j = 1; j <= i / 1000; j ++) {
            roman[i] += 'M';
        }
        roman[i] += roman[i % 1000];
    }
    
    auto calculate = [](string roman) {
        int value = 0;
        for (auto i: roman) {
            if (i == 'I') value ++;
            else if (i == 'V') value += 5;
            else if (i == 'X') value += 10;
            else if (i == 'L') value += 50;
            else if (i == 'C') value += 100;
            else if (i == 'D') value += 500;
            else if (i == 'M') value += 1000;
            else exit(0);
        }
        for (int i = 0; i < (int)roman.size() - 1; i ++) {
            if (roman[i] == 'I' && roman[i + 1] == 'V') {
                value -= 5 + 1 - 4;
            }
            else if (roman[i] == 'I' && roman[i + 1] == 'X') {
                value -= 10 + 1 - 9;
            }
            else if (roman[i] == 'X' && roman[i + 1] == 'L') {
                value -= 50 + 10 - 40;
            }
            else if (roman[i] == 'X' && roman[i + 1] == 'C') {
                value -= 100 + 10 - 90;
            }
            else if (roman[i] == 'C' && roman[i + 1] == 'D') {
                value -= 500 + 100 - 400;
            }
            else if (roman[i] == 'C' && roman[i + 1] == 'M') {
                value -= 1000 + 100 - 900;
            }
        }
        return value;
    };
    
    string line;
    int result = 0;
    while (cin >> line) {
        int value = calculate(line);
        result += (int)line.size() - (int)roman[value].size();
        cout << "line = " << line << ", value = " << value << " --> " << roman[value] << endl;
        cout << result << endl;
    }
    cout << result << endl;
    
    //cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
