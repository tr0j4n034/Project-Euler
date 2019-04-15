//
//  main.cpp
//  practice
//
//  Created by Mahmud on 04/30/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MAX = 1000000005;

int good(int N) {
    vector<int> v;
    while (N > 0) {
        v.push_back(N % 10);
        N /= 10;
    }
    //sort(v.begin(), v.end());
    int a = 0, b = 0;
    for (int i = 1; i < (int)v.size(); i ++) {
        if (v[i] > v[i - 1]) a = 1;
        if (v[i] < v[i - 1]) b = 1;
    }
    if (a + b == 2) return 1;
    return 0;
}

int main() {
    int s = 0;
    for (int i = 1; i < MAX; i ++) {
        int f = good(i);
        s += f;
        if (100LL * s == 99LL * i) {
            cout << i << " " << s << endl;
            return 0;
        }
        if (100LL * s > 99LL * i) {
            cout << "at i = " << i << endl;
            break;
        }
        if (i % 10000000 == 0) cout << i << " --> " << 1. * s / i * 0.99 << endl;
    }
    
    
    return 0;
}
