//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/05/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 10000001;

int power(int a, int b, int modulo) {
    if (b == 0) {
        return 1 % modulo;
    }
    if (b & 1) {
        return 1LL * a * power(a, b - 1, modulo) % modulo;
    }
    else {
        return power(1LL * a * a % modulo, b >> 1, modulo);
    }
}
int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a >= b) a %= b;
        else b %= a;
    }
    return a + b;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int lp[MAX], phi[MAX];

int order(int x, int modulo) {
    int p = phi[modulo];
    int result = p;
    for (int i = 2; i * i <= p; i ++) {
        if (p % i) continue;
        if (power(10, i, modulo) == 1) {
            result = i;
            break;
        }
        if (power(10, p / i, modulo) == 1) {
            result = min(result, p / i);
        }
    }
    return result;
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i < MAX; i ++) {
        if (lp[i]) continue;
        for (int j = i; j < MAX; j += i) {
            lp[j] = i;
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < MAX; i ++) {
        phi[i] = i;
    }
    for (int i = 2; i < MAX; i ++) {
        int j = i;
        while (j % lp[i] == 0) {
            j /= lp[i];
        }
        phi[i] = 1LL * phi[j] * (i / j) * (lp[i] - 1) / lp[i];
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < 10; i ++) {
        cout << i << " --> " << phi[i] << endl;
    }
    cout << endl;
    for (int i = 2; i < MAX; i ++) {
        if (gcd(10, i) != 1) continue;
        int p = i * 9;
        //cout << i << " --> p = " << p << " --> " << order(10, p) << endl;
        if (order(10, p) > 1000000) {
            cout << "found i = " << i << endl;
            break;
        }
    }
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
