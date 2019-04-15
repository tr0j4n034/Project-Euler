//
//  main.cpp
//  practice
//
//  Created by Mahmud on 03/20/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAX = 105;

int N;
int dp[MAX][MAX];

int main()
{
    dp[0][0] = 1;
    
    cin >> N;
    for (int i = 1; i <= N; i ++) {
        for (int j = 0; j <= i; j ++) {
            for (int k = 0; k <= j; k ++) {
                dp[i][j] += dp[i - j][k];
            }
        }
    }
    int result = 0;
    for (int i = 0; i < N; i ++) result += dp[N][i];
    cout << result << endl;
    
    return 0;
}

