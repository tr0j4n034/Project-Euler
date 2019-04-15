//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/18/18.
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

const int MAX = 100001;

long double all = 0;
long double cnt[10];
int binom[11][11];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 0; i < 11; i ++) {
        for (int j = 0; j <= i; j ++) {
            if (j == 0) binom[i][j] = 1;
            else binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
        }
    }
    for (int i = 0; i <= 10; i ++) {
        for (int j = 0; j <= 10; j ++) {
            for (int k = 0; k <= 10/* && i + j + k <= 21*/; k ++) {
                for (int q = 0; q <= 10/* && i + j + k + q <= 21*/; q ++) {
                    for (int l = 0; l <= 10/* && i + j + k + q + l <= 21*/; l ++) {
                        for (int m = 0; m <= 10/* && i + j + k + q + l + m <= 21*/; m ++) {
                            for (int n = 0; n <= 10/* && i + j + k + q + l + m + n <= 21*/; n ++) {
                                if (i + j + k + q + l + m + n == 20) {
                                    int active = 0;
                                    long double ways = 1.;
                                    ways *= binom[10][i];
                                    ways *= binom[10][j];
                                    ways *= binom[10][k];
                                    ways *= binom[10][q];
                                    ways *= binom[10][l];
                                    ways *= binom[10][m];
                                    ways *= binom[10][n];
                                    if (i > 0) active ++;
                                    if (j > 0) active ++;
                                    if (k > 0) active ++;
                                    if (q > 0) active ++;
                                    if (l > 0) active ++;
                                    if (m > 0) active ++;
                                    if (n > 0) active ++;
                                    cnt[active] += ways;
                                    all += ways;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cerr << all << endl;
    long double result = 0.;
    for (int i = 2; i <= 7; i ++) {
        cout << i << " --> " << 1. * (long double)cnt[i] / (long double)all << endl;
        result = (result + 1. * (long double)i * (long double)cnt[i] / (long double)all);
    }
    
    cout.precision(9);
    cout << fixed << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
