//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/03/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAX = 1000000;

vector<int> add(vector<int> a, vector<int> b) {
    for (int i = 0; i < 10; i ++) {
        a[i] += b[i];
    }
    return a;
}
vector<int> add(vector<int> a, int x) {
    vector<int> b(10, 0);
    b[x] = 1;
    return add(a, b);
}
int good(vector<int> &v) {
    for (int i = 0; i < 10; i ++) {
        if (v[i] > 3) {
            return 0;
        }
    }
    return 1;
}

map<vector<int>, long long> m[20];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < 10; i ++) {
        vector<int> v(10, 0);
        v[i] = 1;
        m[1][v] = 1;
    }
    for (int i = 2; i < 19; i ++) {
        for (int j = 0; j < 10; j ++) {
            for (auto old: m[i - 1]) {
                vector<int> current = add(old.first, j);
                if (good(current)) {
                    m[i][current] += old.second;
                }
            }
        }
    }
    long long sum = 0;
    for (auto i : m[18]) {
        sum += i.second;
    }
    cout << sum << endl;
    
    return 0;
}
