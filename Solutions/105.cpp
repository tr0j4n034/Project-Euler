//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/13/18.
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
#include <queue>
#include <utility>
#include <bitset>
#include <cassert>
#include <numeric>
#include <functional>

using namespace std;

const int MAX = 15;

int T = 100, N;
int bits[1 << MAX];
int a[MAX], sum[1 << MAX];

int main() {
    freopen("sets.txt", "r", stdin);
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 0; i < (1 << MAX); i ++) {
        for (int j = 0; j < MAX; j ++) {
            if (i & (1 << j)) {
                bits[i] = bits[i ^ (1 << j)] + 1;
                break;
            }
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    int result = 0;
    for (int c = 0; c < T; c ++) {
        N = 0;
        string s;
        getline(cin, s);
        s += ",";
        int x = 0;
        for (int i : s) {
            if (i == ',') {
                a[N ++] = x;
                x = 0;
            }
            else {
                x = 10 * x + i - '0';
            }
        }
        for (int i = 0; i < (1 << N); i ++) {
            for (int j = 0; j < N; j ++) {
                if (i & (1 << j)) {
                    sum[i] = sum[i ^ (1 << j)] + a[j];
                    break;
                }
            }
        }
        int good = 1;
        for (int i = 1; i < (1 << N) - 1; i ++) {
            for (int j = i + 1; j < (1 << N) - 1; j ++) {
                if (i & j) continue;
                if (!good) break;
                if (sum[i] == sum[j]) good = 0;
                if (bits[i] > bits[j] && sum[i] < sum[j]) good = 0;
                if (bits[j] > bits[i] && sum[j] < sum[i]) good = 0;
            }
        }
        if (good) result += sum[(1 << N) - 1];
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
