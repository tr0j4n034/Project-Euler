//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/15/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>

/*
 http://oeis.org/A000041
 https://en.wikipedia.org/wiki/Pentagonal_number
 */

using namespace std;

const int S = 100005;
const int MODULO = 1000000;

//int dp[S][S], sum[S][S];
long long a[S];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    //    dp[0][0] = 1;
    //    for (int i = 1; i < 20; i ++) {
    //        for (int j = 1; j <= i; j ++) {
    //            dp[i][j] = sum[i - j][min(i - j, j)];
    //            sum[i][j] = sum[i][j - 1] + dp[i][j];
    //            dp[i][j] %= MODULO;
    //            sum[i][j] %= MODULO;
    ////            for (int k = 1; k <= i - j && k <= j; k ++) {
    ////                dp[i][j] += dp[i - j][k];
    ////            }
    //        }
    //        dp[i][i] = 1;
    //        sum[i][i] += 1;
    //        sum[i][i] %= MODULO;
    ////        int s = 0;
    ////        for (int j = 1; j <= i; j ++) {
    ////            s += dp[i][j];
    ////        }
    //        cout << i << " " << sum[i][i] << endl;
    //    }
    
    a[0] = 1;
    for (int i = 1; i < S; i ++) {
        for (int j = 1; 1LL * j * (3 * j - 1) / 2 <= i; j ++) {
            //cout << "for i = " << i << " " << j << endl;
            int k = j * (3 * j - 1) / 2;
            if (((j >> 1) + 1) & 1) {
                a[i] -= a[i - k];
            }
            else {
                a[i] += a[i - k];
            }
        }
        for (int j = -1; 1LL * j * (3 * j - 1) / 2 <= i; j --) {
            int k = j * (3 * j - 1) / 2;
            if (((-j + 1) >> 1) & 1) {
                a[i] += a[i - k];
            }
            else {
                a[i] -= a[i - k];
            }
        }
        //if (a[i] < 0) a[i] = -a[i];
        a[i] %= MODULO;
        cout << i << " --> " << a[i] << endl;
        if (a[i] % MODULO == 0) {
            cout << i << endl;
            return 0;
        }
    }
    
    
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

