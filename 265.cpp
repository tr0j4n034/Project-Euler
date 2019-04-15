//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/28/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 305;
const int M = 5;

long long sum = 0;
int was[N];
set<long long> found;

long long convert(vector<int> bag) {
    vector<int> smallestShift = bag;
    for (int i = 0; i < (1 << M); i ++) {
        vector<int> currentBag;
        for (int j = 0; j < (1 << M) - 1; j ++) {
            currentBag.push_back(bag[j + 1]);
        }
        currentBag.push_back(bag[0]);
        if (currentBag < smallestShift) {
            smallestShift = currentBag;
        }
        bag = currentBag;
    }
    long long value = 0;
    for (auto i: smallestShift) {
        value = (value << 1) | i;
    }
    return value;
}
void go(vector<int> bag, int length) {
    if (length == (1 << M)) {
        int good = 1;
        vector<int> extra;
        for (int i = M - 1; i > 0 && good; i --) {
            int now = 0;
            for (int j = i; j > 0; j --) {
                now = (now << 1) | bag[length - j];
            }
            for (int j = 0; j < M - i; j ++) {
                now = (now << 1) | bag[j];
            }
            if (was[now]) {
                good = 0;
            }
            else {
                was[now] = 1;
                extra.push_back(now);
            }
        }
        if (good) {
            long long v = convert(bag);
            if (!found.count(v)) {
                cout << v << endl;
                sum += v;
                found.insert(v);
            }
        }
        for (int i: extra) {
            was[i] = 0;
        }
        return;
    }
    if (length < M - 1) {
        for (int i = 0; i < 2; i ++) {
            vector<int> currentBag = bag;
            currentBag.push_back(i);
            go(currentBag, length + 1);
        }
    }
    else {
        for (int i = 0; i < 2; i ++) {
            vector<int> currentBag = bag;
            int last = 0;
            for (int j = M - 1; j > 0; j --) {
                last = (last << 1) | bag[length - j];
            }
            if (!was[(last << 1) | i]) {
                currentBag.push_back(i);
                was[(last << 1) | i] = 1;
                go(currentBag, length + 1);
                was[(last << 1) | i] = 0;
            }
        }
    }
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    go(vector<int>(), 0);
    cout << sum << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

