//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/19/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <cassert>

using namespace std;

const int MAX = 338350 + 1;

int ways[MAX][51];
int was[MAX];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    int sum = 0;
    for (int i = 1; i <= 100; i ++) sum += i * i;
    cerr << sum << endl;
    
    for (int i = 1; i <= 100; i ++) {
        int v = i * i;
        for (int j = 50; j > 1; j --) {
            for (int k = MAX - 1 - v; k > 0; k --) {
                ways[k + v][j] = (ways[k + v][j] + ways[k][j - 1]) % 123456789;
            }
        }
        ways[v][1] = (ways[v][1] + 1) % 123456789;
        for (int j = 1; j < MAX; j ++) {
            if (ways[j][50] > 1) {
                was[j] = 1;
            }
        }
    }
    long long result = 0;
    for (int i = 1; i < MAX; i ++) {
        if (!was[i] && ways[i][50] == 1) result += i;
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
