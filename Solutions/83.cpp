//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/4/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#pragma GCC optimize("-0g")

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <ctime>

using namespace std;

const int MAX = 101;

int N;
int a[MAX][MAX];
int dp[MAX][MAX];

void update(int &a, int b) {
    if (a > b) a = b;
}

int main() {
    freopen("matrix.txt", "r", stdin);
    
    N = 80;
    for (int i = 1; i <= N; i ++) {
        string s;
        cin >> s;
        s += ",";
        for (int j = 0, k = 1, x = 0; j < (int)s.size(); j ++) {
            if (s[j] == ',') {
                a[i][k ++] = x;
                x = 0;
            }
            else {
                x = 10 * x + s[j] - '0';
            }
        }
    }
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            dp[i][j] = 1 << 30;
        }
    }
    dp[1][1] = a[1][1];
    for (int _ = 0; _ < 5555; _ ++) {
        for (int i = 1; i <= N; i ++) {
            for (int j = 1; j <= N; j ++) {
                for (int k = -1; k < 2; k ++) {
                    for (int q = -1; q < 2; q ++) {
                        if (k * k + q * q == 1) {
                            if (i + k < 1 || i + k > N || j + q < 1 || j + q > N) continue;
                            if (dp[i + k][j + q] == (1 << 30)) continue;
                            update(dp[i][j], dp[i + k][j + q] + a[i][j]);
                        }
                    }
                }
            }
        }
    }
    cout << dp[N][N] << endl;
    
    return 0;
}

