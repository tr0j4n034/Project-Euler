//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/15/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <utility>

using namespace std;

const int MAX = 50000001;
const int MAGIC = 50;

long double get(long double a, long double b, long double c) {
    long double low = 0., high = b;
    for (int i = 0; i < MAGIC; i ++) {
        long double mid1 = (low + low + high) / 3.;
        long double mid2 = (low + high + high) / 3.;
        long double d1 = sqrtl(a * a + mid1 * mid1) + sqrtl(c * c + (b - mid1) * (b - mid1));
        long double d2 = sqrtl(a * a + mid2 * mid2) + sqrtl(c * c + (b - mid2) * (b - mid2));
        if (d1 > d2) low = mid1;
        else high = mid2;
    }
    return sqrtl(a * a + low * low) + sqrtl(c * c + (b - low) * (b - low));
}
int check(int i, int j, int k) {
    long double a = 1. * i;
    long double b = 1. * j;
    long double c = 1. * k;
    long double d = get(a, b, c);
    d = min(d, get(a, c, b));
    d = min(d, get(b, a, c));
    long double v = floor(d);
    if (abs(v - d) < 1.e-9) {
        //cout << i << " " << j << " " << k << " " << (int)v << endl;
        return 1;
    }
    else {
        return 0;
    }
}

map<int, int> squares;
long long counts[MAX];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i * i < MAX; i ++) {
        squares[i * i] = i;
    }
    for (int i = 1; i * i < MAX; i ++) {
        for (int j = i; i * i + j * j < MAX; j ++) {
            if (squares.count(i * i + j * j)) {
                counts[j] += (i >> 1);
                for (int k = 1; k + k <= j; k ++) {
                    if (j - k > i) continue;
                    counts[i] ++;
                }
            }
        }
    }
    long long nneed = 1000000, have = 0;
    for (int i = 1; i < MAX; i ++) {
        have += counts[i];
        if (have >= nneed) {
            cout << "found at " << i << endl;
            return 0;
        }
        cout << i << " " << have << endl;
    }
    cout << have << endl;
    return 0;
    
    int M = 100, ways = 0, need = 1000000 + 1;
    for (int m = 1; m < 555; m ++) {
        M = m;
        ways += check(M, M, M);
        for (int i = 1; i < M; i ++) {
            ways += check(i, M, M);
        }
        for (int i = 1; i < M; i ++) {
            for (int j = i; j < M; j ++) {
                ways += check(i, j, M);
            }
        }
        //cout << "at M = " << M << " to " << ways << endl;
    }
    cout << ways << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

