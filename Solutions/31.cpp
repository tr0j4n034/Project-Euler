//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/14/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int v[] = {0, 1, 2, 5, 10, 20, 50, 100, 200};
long long dp[10][300];

int main() {
    dp[0][0] = 1;
    for (int i = 1; i <= 8; i ++) {
        for (int j = 0; j <= 200; j ++) {
            for (int k = j; k >= 0; k -= v[i]) dp[i][j] += dp[i - 1][k];
        }
    }
    cout << dp[8][200] << endl;
    
    return 0;
}
