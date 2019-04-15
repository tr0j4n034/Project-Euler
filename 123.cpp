//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/6/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#pragma GCC optimize("-0g")

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <utility>
#include <cassert>

using namespace std;

const int MAX = 2000005;

int N = 0;
int p[MAX], primes[MAX];

long long multiply(long long a, long long b, long long modulo) {
    if (b == 0) return 0;
    if (b & 1) return (multiply(a, b - 1, modulo) + a) % modulo;
    else return (multiply(a, b >> 1, modulo) * 2) % modulo;
}
long long power(int a, int b, long long modulo) {
    if (b == 0) return 1 % modulo;
    else if(b & 1) return multiply(a, power(a, b - 1, modulo), modulo);
    long long half = power(a, b >> 1, modulo);
    return multiply(half, half, modulo);
}

int main() {
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        primes[++N] = i;
        for (int j = i + i; j < MAX; j += i) {
            p[j] = 1;
        }
    }
    long long offset = 10000000000LL;
    for (int i = 1; i <= N; i ++) {
        long long f = power(primes[i] - 1, i, 1LL * primes[i] * primes[i]);
        long long s = power(primes[i] + 1, i, 1LL * primes[i] * primes[i]);
        long long now = (f + s) % (1LL * primes[i] * primes[i]);
        if (now > offset) {
            cout << i << endl;
            break;
        }
    }
    
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
