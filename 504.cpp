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

const int N = 100;
bool good[4 * N * N * N * N];

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a >= b) a %= b;
        else b %= a;
    }
    return a + b;
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    for (int i = 0; i <= 2 * N * N; i ++) {
        good[i * i] = 1;
    }
    int result = 0;
    for (int a = 1; a <= N; a ++) {
        for (int b = 1; b <= N; b ++) {
            for (int c = 1; c <= N; c ++) {
                for (int d = 1; d <= N; d ++) {
                    int s = (a * b + b * c + c * d + d * a) / 2;
                    int boundary = gcd(a, b) + gcd(b, c) + gcd(c, d) + gcd(d, a);
                    int interior = s - boundary / 2 + 1;
                    if (good[interior]) result ++;
                    //                    if (a == 1 && b == 1 && c == 1 && d == 2) {
                    //                        cout << s << " " << boundary << " " << interior << endl;
                    //                    }
                    //                    if (good[interior]) {
                    //                        cout << a << " " << b << " " << c << " " << d << " ---> " << interior << endl;
                    //                    }
                }
            }
        }
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
