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

const int MAX = 1000001;

int maxChain = -1, id = -1;
int d[MAX];

int main() {
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < MAX; i ++) {
        for (int j = i + i; j < MAX; j += i) {
            d[j] += i;
        }
    }
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < MAX; i ++) {
        int l = -1, j = i;
        for (int k = 1; k <= 3000; k ++) {
            j = d[j];
            if (j >= MAX) break;
            if (j == i) {
                l = k + 1;
                break;
            }
        }
        if (l > maxChain) {
            maxChain = l;
            id = i;
        }
    }
    cout << id << endl;
    
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
