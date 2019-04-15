//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/01/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10005;

int mask[MAX];
vector<int> values[105];

int found = 0;

void go(vector<int> soFar, int currentMask) {
    if (found) return;
    if ((int)soFar.size() == 6) {
        if (soFar.back() % 100 != soFar.front() / 100) {
            return;
        }
        found = 1;
        for (auto i : soFar) {
            cerr << i << endl;
        }
        int sum = 0;
        for (auto i : soFar) {
            sum += i;
        }
        cout << "sum = " << sum << endl;
        return;
    }
    for (auto i : values[soFar.back() % 100]) {
        for (int j = 0; j < 6; j ++) {
            if (!(currentMask & (1 << j)) && (mask[i] & (1 << j))) {
                vector<int> to = soFar;
                to.push_back(i);
                int nextMask = currentMask | (1 << j);
                go(to, nextMask);
            }
        }
    }
}

int main() {
    for (int i = 1; i < 333; i ++) {
        int value = i * (i + 1) / 2;
        if (value >= MAX) break;
        mask[value] |= 1;
        value = i * i;
        if (value < MAX) mask[value] |= 2;
        value = i * (3 * i - 1) / 2;
        if (value < MAX) mask[value] |= 4;
        value = i * (2 * i - 1);
        if (value < MAX) mask[value] |= 8;
        value = i * (5 * i - 3) / 2;
        if (value < MAX) mask[value] |= 16;
        value = i * (3 * i - 2);
        if (value < MAX) mask[value] |= 32;
    }
    for (int i = 1000; i < 10000; i ++) {
        if (mask[i] != 0) {
            values[i / 100].push_back(i);
        }
    }
    for (int i = 1000; i < 10000; i ++) {
        for (int j = 0; j < 6; j ++) {
            if (mask[i] & (1 << j)) {
                go(vector<int>(1, i), 1 << j);
            }
        }
    }
    
    return 0;
}
