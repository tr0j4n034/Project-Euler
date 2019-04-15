//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/21/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

const int S = 20;

void print(unsigned long long n) {
    if (n < 16) {
        if (n < 10) cout << n;
        else cout << (char)('A' + n - 10);
        return;
    }
    print(n / 16);
    int r = n % 16;
    if (r < 10) cout << r;
    else cout << (char)('A' + r - 10);
};

long long dp[S][10];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < 16; i ++) {
        if (i < 3) {
            dp[1][1 << i] ++;
        }
        else {
            dp[1][0] ++;
        }
    }
    long long result = 0;
    for (int i = 2; i <= 16; i ++) {
        for (int j = 0; j < 8; j ++) {
            for (int k = 0; k < 16; k ++) {
                for (int q = 0; q < 8; q ++) {
                    int added = (k < 3 ? (1 << k) : 0);
                    if ((q | added) == j) {
                        dp[i][j] += dp[i - 1][q];
                    }
                }
            }
        }
        cout << "at i = " << i << " " << dp[i][7] << endl;
        result += dp[i][7];
    }
    print(result);
    cout << endl;
    return 0;
    
    int s = 0;
    for (int i = 1; i < 16; i ++) {
        for (int j = 0; j < 16; j ++) {
            for (int k = 0; k < 16; k ++) {
                for (int q = 0; q < 16; q ++) {
                    for (int l = 0; l < 16; l ++) {
                        int f1 = 0, f2 = 0, f3 = 0;
                        if (i == 0 || j == 0 || k == 0 || q == 0 || l == 0) f1 = 1;
                        if (i == 1 || j == 1 || k == 1 || q == 1 || l == 1) f2 = 1;
                        if (i == 10 || j == 10 || k == 10 || q == 10 || l == 10) f3 = 1;
                        if (f1 && f2 && f3) s ++;
                    }
                }
            }
        }
    }
    cout << s << endl;
    // 4, 258, 9928
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

