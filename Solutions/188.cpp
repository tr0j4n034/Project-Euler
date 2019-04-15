//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/08/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAX = 100005;

int lp[MAX];
vector<int> primes;
map<int, int> phi;

int getPhi(int N) {
    if (N == 1) return 1;
    if (phi.count(N)) return phi[N];
    int d = N;
    for (int i: primes) {
        if (N % i == 0) {
            d = i;
            break;
        }
    }
    int M = N;
    while (M % d == 0) {
        M /= d;
    }
    return phi[N] = 1LL * getPhi(M) * (N / M) / d * (d - 1);
}

int power(int a, int b, int modulo) {
    if (b == 0) return 1 % modulo;
    if (b & 1) return 1LL * a * power(a, b - 1, modulo) % modulo;
    else return power(1LL * a * a % modulo, b >> 1, modulo);
}
int tetration(int a, int b, int modulo) {
    if (b == 1) return a % modulo;
    else {
        int exponent = tetration(a, b - 1, getPhi(modulo));
        return power(a, exponent, modulo);
    }
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i < MAX; i ++) {
        if (lp[i]) continue;
        primes.push_back(i);
        for (int j = i; j < MAX; j += i) {
            lp[j] = i;
        }
    }
    int a = 1777, b = 1855;
    cout << tetration(a, b, 100000000) << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
