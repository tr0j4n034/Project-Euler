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

const int MAX = 40000000;

int N;
int lp[MAX], phi[MAX];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;

    for (int i = 1; i < MAX; i ++) phi[i] = i;
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;

    for (int i = 2; i < MAX; i ++) {
        if (lp[i]) continue;
        for (int j = i; j < MAX; j += i) {
            lp[j] = i;
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    phi[1] = 1;
    for (int i = 2; i < MAX; i ++) {
        int j = i / lp[i];
        if (j % lp[i] == 0) phi[i] = phi[j] * lp[i];
        else phi[i] = phi[j] * (lp[i] - 1);
    }
    
    long long result = 0;
    int x = 25;
    
    for (int i = 2; i < MAX; i ++) {
        if (lp[i] != i) continue;
        
        int j = i, steps = 1;
        while (j > 1) {
            if (steps > 25) break;
            steps ++;
            j = phi[j];
        }
        if (steps == 25) result += i;
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
