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

const int MAX = 20000000;

long long get(long long n, long long k) {
    long long s = 0, p = k;
    while (p <= n) {
        s += n / p;
        p *= k;
    }
    return s;
}

int p[MAX];

int main() {
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    long long a = 20000000, b = 15000000;
    long long result = 0;
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        result += (get(a, i) - get(b, i) - get(a - b, i)) * i;
        for (int j = i + i; j < MAX; j += i) {
            p[j] = 1;
        }
    }
    cout << result << endl;
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
