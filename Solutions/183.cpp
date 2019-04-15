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

const int MAX = 105;

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a >= b) a %= b;
        else b %= a;
    }
    return a + b;
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    int N = 10000;
    int sum = 0;
    for (int i = 5; i <= N; i ++) {
        int best = 2;
        for (int j = 2; j <= i; j ++) {
            if (1. * j * log(1. * i / j) > 1. * best * log(1. * i / best)) {
                best = j;
            }
        }
        int d = best / gcd(i, best);
        while (d % 2 == 0) d /= 2;
        while (d % 5 == 0) d /= 5;
        if (d > 1) sum += i;
        else sum -= i;
    }
    cout << sum << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
