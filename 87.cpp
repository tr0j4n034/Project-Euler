//
//  main.cpp
//  practice
//
//  Created by Mahmud on 04/30/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

const int MAX = 50000000;


int cnt = 0;
int p[MAX];
int primes[MAX];
int f[MAX];

int main() {
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        primes[++cnt] = i;
        for (int j = i + i; j < MAX; j += i) p[j] = 1;
    }
    cout << "elapsed: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i <= cnt; i ++) {
        int now = primes[i] * primes[i] * primes[i] * primes[i];
        if (now >= MAX) break;
        for (int j = 1; j <= cnt; j ++) {
            if (now + primes[j] * primes[j] * primes[j] >= MAX) break;
            f[now + primes[j] * primes[j] * primes[j]] = 1;
        }
    }
    cout << "elapsed: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    int s = 0;
    for (int i = 1; i < MAX; i ++) {
        for (int j = 1; j <= cnt; j ++) {
            if (i < primes[j] * primes[j]) break;
            if (f[i - primes[j] * primes[j]]) {
                s ++;
                break;
            }
        }
    }
    cout << "elapsed: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    cout << s << endl;
    
    return 0;
}
