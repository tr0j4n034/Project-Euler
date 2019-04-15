//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/19/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <cassert>

using namespace std;

const int MAX = 100000000;

int N = MAX - 1;
int lp[MAX], f[MAX];

int get(int n, int k) {
    int s = 0;
    while (n % k == 0) {
        s ++;
        n /= k;
    }
    return s;
}
int power(int a, int b, int modulo) {
    if (b == 0) return 1 % modulo;
    if (b & 1) return 1LL * power(a, b - 1, modulo) * a % modulo;
    return power(1LL * a * a % modulo, b >> 1, modulo);
}
int inverse(int a, int modulo) {
    return power(a, modulo - 2, modulo);
}
int naive(int n) {
    int result = 0;
    for (int i = 1; i <= 5; i ++) {
        int f = 1;
        for (int j = 1; j <= n - i; j ++) {
            f = f * j % n;
        }
        result += f;
    }
    return result % n;
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
    
    long long result = 0;
    for (int i = 5; i < MAX; i ++) {
        if (lp[i] == i) {
            int now = i - 1;
            int sum = 0;
            for (int j = 1; j <= 5; j ++) {
                sum = (sum + now) % i;
                now = 1LL * now * inverse(i - j, i) % i;
            }
            result += sum;
        }
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
