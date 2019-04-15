//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/03/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int MAX = 1000000;

int digitSum(int N) {
    int s = 0;
    while (N > 0) {
        s += N % 10;
        N /= 10;
    }
    return s;
}

int d[MAX], f[MAX];
vector<int> divisors[MAX];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < MAX; i ++) {
        d[i] = digitSum(i);
        while (d[i] > 9) {
            d[i] = digitSum(d[i]);
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i < MAX; i ++) {
        for (int j = i + i; j < MAX; j += i) {
            divisors[j].push_back(i);
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    long long sum = 0;
    for (int i = 1; i < MAX; i ++) {
        f[i] = d[i];
        for (int j: divisors[i]) {
            f[i] = max(f[i], f[j] + f[i / j]);
        }
        if (i > 1) sum += f[i];
        if (i == 24) cout << f[i] << endl;
    }
    cout << sum << endl;
    
    return 0;
}
