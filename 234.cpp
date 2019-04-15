//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/23/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

const int S = 11000005;
const long long UP = 999966663333LL + 1;

int p[S];
int lower[S], upper[S];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i < S; i ++) {
        if (p[i]) continue;
        for (int j = i + i; j < S; j += i) {
            p[j] = 1;
        }
    }
    for (int i = 2; i < S; i ++) {
        if (!p[i]) lower[i] = i;
        else lower[i] = lower[i - 1];
    }
    for (int i = S - 2; i > 1; i --) {
        if (!p[i + 1]) upper[i] = i + 1;
        else upper[i] = upper[i + 1];
    }
    //    long long cnt = 0;
    //    for (int i = 4; i < min(UP, 10000LL); i ++) {
    //        int root = 0;
    //        for (int j = 1; j * j <= i; j ++) {
    //            root = j;
    //        }
    //        int d = 0;
    //        for (int j = root; j > 0; j --) {
    //            if (!p[j]) {
    //                d += (int)(i % j == 0);
    //                break;
    //            }
    //        }
    //        for (int j = root; ; j ++) {
    //            if (j * j < i) continue;
    //            if (!p[j]) {
    //                d += (int)(i % j == 0);
    //                break;
    //            }
    //        }
    //        if (d == 1) {
    //            cout << i << ", ";
    //            cnt += i;
    //        }
    //    }
    //    cout << endl;
    //    cout << "cnt = " << cnt << endl;
    
    auto sum = [&](long long high, long long x) {
        if (high < x) return 0ULL;
        long long n = high / x;
        if (n % 2 == 0) return 1ULL * n / 2 * (x + high / x * x);
        else return 1ULL * (x + high / x * x) / 2 * n;
    };
    auto getCount = [&](long long low, long long high, long long x) {
        return sum(high, x) - sum(low - 1, x);
    };
    unsigned long long result = 0;
    for (int root = 2; 1LL * root * root < UP; root ++) {
        int lps = lower[root];
        int ups = upper[root];
        long long low = 1LL * root * root + 1;
        long long high = 1LL * (root + 1) * (root + 1) - 1;
        high = min(high, UP - 1);
        unsigned long long has = getCount(low, high, lps) + getCount(low, high, ups) - 2 * getCount(low, high, 1LL * lps * ups);
        //cout << root << ", lps = " << lps << ", ups = " << ups << " has = " << has << endl;
        result += has;
    }
    cout << "count = " << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

