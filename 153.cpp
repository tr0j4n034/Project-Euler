//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/4/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <ctime>

using namespace std;

const int N = 100000001;

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a >= b) a %= b;
        else b %= a;
    }
    return a + b;
}

int lp[N];
long long f[N], g[N];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < N; i ++) {
        for (int j = i; j < N; j += i) {
            f[j] += i;
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i * i < N; i ++) {
        for (int j = 1; i * i + j * j < N; j ++) {
            if (gcd(i, j) > 1) continue;
            g[i * i + j * j] += 2 * i;
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = N - 1; i > 0; i --) {
        for (int j = i + i; j < N; j += i) {
            g[j] += 1LL * g[i] * f[j / i];
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    long long sum = 0;
    for (int i = 1; i < N; i ++) {
        sum += f[i] + g[i];
    }
    cout << sum << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

