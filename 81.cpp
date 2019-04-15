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
#include <utility>

using namespace std;

const int MAX = 1005;

int N = 80;
int a[MAX][MAX];
int dp[MAX][MAX];

int main() {
    freopen("matrix.txt", "r", stdin);
    
    for (int i = 1; i <= N; i ++) {
        string s;
        getline(cin, s);
        s += ",";
        for (int j = 0, k = 1, c = 0; j < (int)s.size(); j ++) {
            if (s[j] == ',') {
                a[i][k] = c;
                k ++;
                c = 0;
            }
            else {
                c = 10 * c + s[j] - '0';
            }
        }
    }
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            if (i == 1 && j == 1) dp[i][j] = a[i][j];
            else if(i == 1) dp[i][j] = dp[i][j - 1] + a[i][j];
            else if(j == 1) dp[i][j] = dp[i - 1][j] + a[i][j];
            else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
        }
    }
    cout << dp[N][N] << endl;
    
    return 0;
}
