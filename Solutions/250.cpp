//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/10/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <bitset>
#include <cassert>

using namespace std;

const int MAX = 255;
const long long MOD = 10000000000000000LL;

int counts[MAX];
long long dp[MAX], temp[MAX];

void add(long long &a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
}
int power(int a, int b, int modulo = 250) {
    if (b == 0) return 1 % modulo;
    if (b & 1) return 1LL * power(a, b - 1, modulo) * a % modulo;
    return power(1LL * a * a % modulo, b >> 1, modulo);
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i <= 250250; i ++) {
        counts[power(i % 250, i)] ++;
    }
    //dp[0] = 1;
    for (int i = 0; i < 250; i ++) {
        cout << i << " --> " << counts[i] << endl;
        for (int j = 1; j <= counts[i]; j ++) {
            for (int k = 0; k < 250; k ++) {
                temp[k] = dp[k];
            }
            for (int k = 250 - 1; k >= 0; k --) {
                add(dp[(k + i) % 250], temp[k]);
            }
            add(dp[i], 1);
        }
    }
    cout << dp[0] << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
