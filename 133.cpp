//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/10/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 100000;

int power(int a, int b, int modulo) {
    if (b == 0) return 1 % modulo;
    if (b & 1) return 1LL * a * power(a, b - 1, modulo) % modulo;
    else return power(1LL * a * a % modulo, b >> 1, modulo);
}
int order(int a, int modulo) {
    int N = modulo - 1;
    int best = N;
    for (int i = 1; i * i <= N; i ++) {
        if (N % i == 0) {
            if (i < best && power(a, i, modulo) == 1) {
                best = i;
            }
            if (N / i < best && power(a, N / i, modulo) == 1) {
                best = N / i;
            }
        }
    }
    return best;
}
int check(int order) {
    while (order % 2 == 0) order /= 2;
    while (order % 5 == 0) order /= 5;
    return (order == 1 ? 1 : 0);
}

int p[MAX];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    long long all = 0;
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        all += i;
        for (int j = i + i; j < MAX; j += i) {
            p[j] = 1;
        }
    }
    long long sum = 0;
    for (int i = 10; i < MAX; i ++) {
        if (i == 27961) {
            cout << i << " ----> " << p[i] << " vs " << order(10, i) << endl;
        }
        if (!p[i] && check(order(10, i))) {
            sum += i;
            cout << i << " --> " << order(10, i) << endl;
        }
    }
    cout << all - sum << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
