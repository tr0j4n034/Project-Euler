//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/20/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

const int S = 45000;
const int MAX = 2000000000;

char f[MAX];
int sq[S];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < S; i ++) {
        sq[i] = i * i;
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < S; i ++) {
        for (int j = 1; j < S; j ++) {
            if (1LL * sq[i] + sq[j] < MAX) {
                f[sq[i] + sq[j]] |= 1;
            } else {
                break;
            }
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < S; i ++) {
        for (int j = 1; j < S; j ++) {
            if (1LL * sq[i] + 2LL * sq[j] < MAX) {
                f[sq[i] + 2 * sq[j]] |= 2;
            } else {
                break;
            }
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < S; i ++) {
        for (int j = 1; j < S; j ++) {
            if (1LL * sq[i] + 3LL * sq[j] < MAX) {
                f[sq[i] + 3 * sq[j]] |= 4;
            } else {
                break;
            }
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < S; i ++) {
        for (int j = 1; j < S; j ++) {
            if (1LL * sq[i] + 7LL * sq[j] < MAX) {
                f[sq[i] + 7 * sq[j]] |= 8;
            } else {
                break;
            }
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    int counts = 0;
    for (int i = 1; i < MAX; i ++) {
        if (f[i] == 15) {
            ++counts;
        }
    }
    cout << counts << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

