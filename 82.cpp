//
//  main.cpp
//  practice
//
//  Created by Mahmud on 04/30/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

const int MAX = 100;

int N = 80;
int a[MAX][MAX];
int dp[MAX][MAX];

int main() {
    freopen("matrix.txt", "r", stdin);
    
    for (int i = 1; i <= N; i ++) {
        string s;
        getline(cin, s);
        s += ",";
        int j = 1, x = 0;
        for (int k = 0; k < (int)s.size(); k ++) {
            if (s[k] == ',') {
                a[i][j ++] = x;
                x = 0;
            }
            else {
                x = 10 * x + s[k] - '0';
            }
        }
    }
    for (int j = 1; j <= N; j ++) {
        for (int i = 1; i <= N; i ++) {
            if (j == 1) {
                dp[i][j] = a[i][j];
            }
            else {
                dp[i][j] = dp[i][j - 1] + a[i][j];
            }
        }
        for (int k = 1; k <= N; k ++) {
            for (int q = 1; q <= N; q ++) {
                if (q == 1) dp[q][j] = min(dp[q][j], dp[q + 1][j] + a[q][j]);
                else if (q == N) dp[q][j] = min(dp[q][j], dp[q - 1][j] + a[q][j]);
                else {
                    dp[q][j] = min(dp[q][j], min(dp[q - 1][j], dp[q + 1][j]) + a[q][j]);
                }
            }
        }
    }
    int best = dp[1][N];
    for (int i = 1; i <= N; i ++) best = min(best, dp[i][N]);
    cout << best << endl;
    
    return 0;
}
