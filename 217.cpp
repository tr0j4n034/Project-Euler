//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/01/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <bitset>
#include <ctime>
#include <cassert>

using namespace std;

const int MAX = 505;
const int SZ = 47;
const int MODULO = 14348907; // 3^15

long long power[MAX];
long long counts[SZ + 1][MAX], sum[SZ + 1][MAX];

void add(long long &a, long long b) {
    a += b;
}
int brute(int N) {
    int sum = 0;
    for (int i = (int)power[N - 1]; i < (int)power[N]; i ++) {
        //cout << i << endl;
        string s = to_string(i);
        int c = 0;
        for (int k = 1; k <= (int)s.size(); k ++) {
            if (k + k < (int)s.size()) c += s[k - 1] - '0';
            else if(k + k > (int)s.size() + 1) c -= s[k - 1] - '0';
        }
        //cout << i << "--> " << c << endl;
        if (c == 0) sum += i;
    }
    return sum;
}
void relax(long long &a, long modulo) {
    if (a >= modulo) {
        a %= modulo;
    }
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    int N = 47;
    
    for (int i = 0; i < SZ; i ++) {
        if (i == 0) power[i] = 1;
        else power[i] = power[i - 1] * 10;
    }
    long long result = 0;
    for (int L = 1; L <= N; L ++) {
        for (int i = 1; i <= L; i ++) {
            for (int j = 0; j <= 9 * L; j ++) {
                counts[i][j] = 0;
                sum[i][j] = 0;
            }
        }
        for (int i = 1; i <= 9; i ++) {
            if (L == 1) {
                counts[1][0] += 1;
                sum[1][0] += i;
            }
            else {
                counts[1][i] += 1;
                sum[1][i] += i;
            }
        }
        for (int i = 2; i <= L; i ++) {
            for (int j = 0; j < i * 10; j ++) {
                for (int k = 0; k < 10; k ++) {
                    if (i <= L / 2) {
                        if (j < k) continue;
                        counts[i][j] += counts[i - 1][j - k];
                        sum[i][j] += 10LL * sum[i - 1][j - k] + 1LL * counts[i - 1][j - k] * k;
                    }
                    else if (i + i - 1 == L) {
                        counts[i][j] += counts[i - 1][j];
                        sum[i][j] += 10LL * sum[i - 1][j] + 1LL * counts[i - 1][j] * k;
                    }
                    else {
                        if (j + k > 9 * i) continue;
                        counts[i][j] += counts[i - 1][j + k];
                        sum[i][j] += 10LL * sum[i - 1][j + k] + 1LL * counts[i - 1][j + k] * k;
                    }
                    relax(counts[i][j], MODULO);
                    relax(sum[i][j], MODULO);
                }
            }
        }
        result += sum[L][0];
        relax(result, MODULO);
        cout << L << " --> " << sum[L][0] << endl;
    }
    cerr << "result = " << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
