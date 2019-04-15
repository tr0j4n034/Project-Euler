//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/22/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

const int S = 100000000 + 1;
const int UP = 12345;

long long result = 0;

int d[S];
int counts[UP];
set<int> active;

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < S; i ++) {
        for (int j = i; j < S; j += i) {
            d[j] ++;
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    int N = S - 1;
    int K = 100000;
    
    for (int i = 1; i < K; i ++) {
        counts[d[i]] ++;
        active.insert(d[i]);
    }
    for (int i = K; i <= N; i ++) {
        active.insert(d[i]);
        counts[d[i]] ++;
        if (i > K) {
            counts[d[i - K]] --;
            if (!counts[d[i - K]]) {
                active.erase(d[i - K]);
            }
        }
        result += *active.rbegin();
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
