//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/08/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAX = 1 << 26;

int lp[MAX], mu[MAX];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i < MAX; i ++) {
        if (lp[i]) continue;
        for (int j = i; j < MAX; j += i) {
            lp[j] = i;
        }
    }
    mu[1] = 1;
    for (int i = 2; i < MAX; i ++) {
        int j = i / lp[i];
        
        if (mu[j] == 0 || j % lp[i] == 0) mu[i] = 0;
        else mu[i] = -mu[j];
    }
    long long N = (1LL << 50) - 1;
    long long result = 0;
    for (int i = 1; 1LL * i * i <= N; i ++) {
        result += N / (1LL * i * i) * mu[i];
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
