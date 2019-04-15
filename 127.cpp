//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/10/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int S = 120000;

long long gcd(long long a, long long b) {
    while (a > 0 && b > 0) {
        if (a >= b) a %= b;
        else b %= a;
    }
    return a + b;
}
long long lcm(long long a, long long b) {
    return 1LL * a * b / gcd(a, b);
}

int lp[S], rad[S];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i < S; i ++) {
        if (lp[i]) continue;
        for (int j = i; j < S; j += i) {
            lp[j] = i;
        }
    }
    rad[1] = 1;
    for (int i = 2; i < S; i ++) {
        int j = i;
        while (j % lp[i] == 0) {
            j /= lp[i];
        }
        rad[i] = rad[j] * lp[i];
    }
    long long sum = 0;
    for (int c = 1; c < S; c ++) {
        if (c % 10000 == 0) cerr << "now at c = " << c << endl;
        for (int a = 1; a + a < c; a ++) {
            if (gcd(a, c) > 1) continue;
            int b = c - a;
            long long all = lcm(rad[a], lcm(rad[b], rad[c]));
            if (all < c) sum += c;
        }
    }
    cout << sum << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

