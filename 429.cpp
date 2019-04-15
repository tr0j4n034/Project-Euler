//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/24/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

const int S = 100000000 + 1;
const int MODULO = 1000000009;

int power(int a, int b, int modulo) {
    if (b == 0) return 1;
    if (b & 1) return 1LL * a * power(a, b - 1, modulo) % modulo;
    return power(1LL * a * a % modulo, b >> 1, modulo);
}

int p[S], lp[S], counts[S], f[S];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i < S; i ++) {
        if (p[i]) continue;
        lp[i] = i;
        for (int j = i + i; j < S; j += i) {
            p[j] = 1;
            lp[j] = i;
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i < S; i ++) {
        int j = i;
        while (j > 1) {
            int d = lp[j];
            while (j % d == 0) {
                counts[d] ++;
                j /= d;
            }
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i < S; i ++) {
        if (p[i]) continue;
        f[i] = power(i, counts[i], MODULO);
        f[i] = 1LL * f[i] * f[i] % MODULO;
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    long long result = 1;
    for (int i = 2; i < S; i ++) {
        if (p[i]) continue;
        result = 1LL * result * (f[i] + 1) % MODULO;
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
