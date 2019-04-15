//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/12/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <bitset>
#include <cassert>
#include <numeric>
#include <functional>

using namespace std;

const int MAX = 2005;

const int MODULO = 1000000000;

long long sum[25][10][MAX], ways[25][10][MAX];

void add(long long &a, long long b) {
    a += b;
    if (a >= MODULO) a %= MODULO;
}

int good(int N) {
    for (int i = 1; i < 50; i ++) {
        if (i * i == N) return 1;
    }
    return 0;
}
int sqSum(int N) {
    int s = 0;
    while (N > 0) {
        s += (N % 10) * (N % 10);
        N /= 10;
    }
    return s;
}
int get(int N) {
    int p = 1;
    for (int i = 1; i <= N; i ++) p *= 10;
    int s = 0;
    for (int i = 1; i < p; i ++) {
        if (good(sqSum(i))) s += i, cout << i << endl;
    }
    return s;
}


int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    int N = 20;
    
    for (int i = 1; i < 10; i ++) {
        ways[1][i][i * i] = 1;
        sum[1][i][i * i] = i;
    }
    for (int i = 2; i <= N; i ++) {
        for (int j = 0; j < 10; j ++) {
            for (int k = 0; k < MAX; k ++) {
                ways[i][j][k] = 0;
                sum[i][j][k] = 0;
                for (int q = 0; q < 10; q ++) {
                    if (k >= j * j) {
                        add(ways[i][j][k], ways[i - 1][q][k - j * j]);
                        add(sum[i][j][k], (10LL * sum[i - 1][q][k - j * j] % MODULO
                                           + 1LL * ways[i - 1][q][k - j * j] * j % MODULO) % MODULO);
                    }
                }
            }
        }
    }
    long long result = 0;
    for (int i = 1; i <= N; i ++) {
        for (int j = 0; j < 10; j ++) {
            for (int k = 1; k * k <= N * 9 * 9; k ++) {
                add(result, sum[i][j][k * k]);
            }
        }
    }
    cout << result << endl;
    //cout << get(N) << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
