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

const int MAX = 64000000;

long long sigma[MAX];

int main() {
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    for (int i = 1; i < MAX; i ++) {
        for (int j = i; j < MAX; j += i) {
            sigma[j] += 1LL * i * i;
            assert(sigma[i] > 0);
        }
    }
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    long long result = 0;
    for (int i = 1; i < MAX; i ++) {
        long long root = (long long)sqrt(sigma[i] + 1.e-10);
        if (root * root == sigma[i]) result += i;
    }
    cout << result << endl;
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    
    return 0;
}
