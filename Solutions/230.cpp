//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/17/18.
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
#include <queue>
#include <utility>
#include <bitset>
#include <cassert>
#include <numeric>
#include <functional>

using namespace std;

const int MAX = 101;

string a = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
string b = "8214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196";

long long getID(int N) {
    long long x = 127 + 19 * N;
    for (int i = 0; i < N; i ++) x *= 7;
    return x;
}

long long len[MAX];

int KthDigit(int N, long long K) {
    assert(len[N] >= K);
    if (N == 1) return a[K - 1] - '0';
    if (N == 2) return b[K - 1] - '0';
    if (K > len[N - 2]) return KthDigit(N - 1, K - len[N - 2]);
    else return KthDigit(N - 2, K);
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    cerr << getID(17) << endl;
    
    len[1] = 100;
    len[2] = 100;
    for (int i = 3; i < MAX; i ++) {
        len[i] = len[i - 1] + len[i - 2];
        cerr << i << " --> " << len[i] << endl;
        if (len[i] > getID(17)) break;
    }
    long long result = 0;
    for (int i = 0; i <= 17; i ++) {
        long long v = 1;
        for (int j = 0; j < i; j ++) v *= 10;
        int M = 0;
        for (int j = 1; j < MAX; j ++) {
            if (len[j] >= getID(i)) {
                M = j;
                break;
            }
        }
        result += v * KthDigit(M, getID(i));
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
