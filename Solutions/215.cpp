//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/29/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

const int N = 32;
const int M = 10;

long long ways = 0;
vector<vector<int>> orders;

void go(vector<int> v, int sum) {
    if (sum >= N) {
        if (sum == N) {
            orders.push_back(v);
        }
        return;
    }
    for (int i = 2; i < 4 && sum + i <= N; i ++) {
        vector<int> bag = v;
        bag.push_back(i);
        go(bag, sum + i);
    }
}

bool canStick[1 << 14][1 << 14];
bool was[N + 1];
long long dp[M + 1][1 << 14];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    go(vector<int>(), 0);
    cout << (int)orders.size() << endl;
    
    for (int i = 0; i < (int)orders.size(); i ++) {
        for (int j = 0; j < (int)orders.size(); j ++) {
            canStick[i][j] = 1;
            for (int k = 0, sum = 0; k < (int)orders[i].size(); k ++) {
                sum += orders[i][k];
                was[sum] = 1;
            }
            for (int k = 0, sum = 0; k < (int)orders[j].size() - 1; k ++) {
                sum += orders[j][k];
                if (was[sum] == 1) {
                    canStick[i][j] = 0;
                    break;
                }
            }
            for (int k = 0, sum = 0; k < (int)orders[i].size(); k ++) {
                sum += orders[i][k];
                was[sum] = 0;
            }
        }
    }
    
    for (int i = 0; i < (int)orders.size(); i ++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= M; i ++) {
        for (int j = 0; j < (int)orders.size(); j ++) {
            for (int k = 0; k < (int)orders.size(); k ++) {
                if (canStick[k][j]) {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
    }
    for (int i = 0; i < (int)orders.size(); i ++) {
        ways += dp[M][i];
    }
    cout << ways << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

