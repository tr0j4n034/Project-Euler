//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/06/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10000001;

int lp[MAX], phi[MAX], f[MAX];

//int power(int a, int b, int modulo) {
//    if (b == 0) return 1 % modulo;
//    if (b & 1) return 1LL * a * power(a, b - 1, modulo) % modulo;
//    else return power(1LL * a * a % modulo, b >> 1, modulo);
//}
int power(int a, int b, int modulo) {
    int result = 1, p = a;
    while (b) {
        if (b & 1) {
            result = 1LL * result * p % modulo;
        }
        b >>= 1;
        p = 1LL * p * p % modulo;
    }
    return result;
}
int inverse(int a, int b) {
    return power(a % b, phi[b] - 1, b);
}
int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a >= b) a %= b;
        else b %= a;
    }
    return a + b;
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i < MAX; i ++) {
        if (lp[i]) continue;
        for (int j = i; j < MAX; j += i) {
            lp[j] = i;
        }
    }
    phi[1] = 1;
    for (int i = 2; i < MAX; i ++) {
        int j = i;
        while (j % lp[i] == 0) {
            j /= lp[i];
        }
        phi[i] = 1LL * phi[j] * (i / j) / lp[i] * (lp[i] - 1);
    }
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i < MAX; i ++) {
        f[i] = 1;
    }
    for (int i = 2; i < MAX; i ++) {
        for (int j = i + i; j < MAX; j += i) {
            int p = i;
            int q = j / i;
            if (gcd(p, q) > 1) continue;
            int r = inverse(p, q) * p;
            if (r > f[j]) f[j] = r;
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    long long result = 0;
    for (int i = 1; i < MAX; i ++) {
        result += f[i];
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
