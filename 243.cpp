//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/12/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAX = 3001;

int phi[MAX];

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a >= b) a %= b;
        else b %= a;
    }
    return a + b;
}
int smaller(int a, int b) {
    if (1LL * phi[a] * (b - 1) < 1LL * phi[b] * (a - 1)) return 1;
    else return 0;
}

int N;
int prime[MAX];
int d[MAX];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    int best = 1;
    for (int i = 1; i < MAX; i ++) {
        for (int j = 1; j <= i; j ++) {
            if (gcd(i, j) == 1) phi[i] ++;
        }
        if (smaller(i, best)) best = i;
        //cout << i << " --> " << best << endl;
        if (i < MAX && phi[i] == i - 1) {
            prime[++N] = i;
        }
    }
    for (int i = 2; i < MAX; i ++) {
        if (phi[i] != i - 1) continue;
        for (int j = i; j < MAX; j += i) {
            d[j] = i;
        }
    }
    
    long long result = 1, p = 1;
    long long s = 1LL << 50;
    for (int i = 2; i < 35; i ++) {
        if (phi[i] != i - 1) continue;
        result *= i;
        p *= i - 1;
        //cout << i << " --> " << result << " vs " << p << endl;
        for (int j = 1; j < MAX; j ++) {
            if (d[j] > i) continue;
            //cout << "at j =  " << j << endl;
            long long to = result * j;
            long long pto = p * j;
            if (to < s && 1. * pto * 94744. < 1. * (to - 1) * 15499.) {
                cout << "better s = " << to << endl;
                s = to;
            }
        }
    }
    cout << s << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

