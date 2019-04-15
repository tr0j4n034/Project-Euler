//
//  main.cpp
//  practice
//
//  Created by Mahmud on 03/20/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAX = 1005;

int N;
int ptr = 0;
int p[MAX], dp[MAX][MAX];

int main()
{
    for (int i = 2; i < MAX; i ++) {
        int f = 1;
        for (int j = 2; j * j <= i; j ++) {
            if (i % j == 0) {
                f = 0;
                break;
            }
        }
        if (f == 1) p[++ptr] = i;
    }
    dp[0][0] = 1;
    for (int i = 1; i < MAX; i ++) {
        for (int j = 1; j <= ptr; j ++) {
            if (p[j] > i) break;
            if (p[j] == i) {
                dp[i][j] = 1;
                break;
            }
            for (int k = 0; k <= j; k ++) {
                dp[i][j] += dp[i - p[j]][k];
            }
        }
        int sum = 0;
        for (int j = 1; j <= ptr; j ++) {
            sum += dp[i][j];
        }
        if (sum > 5000) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}

