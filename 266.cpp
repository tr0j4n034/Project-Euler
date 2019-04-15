//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/20/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int S = 190;
const int N = 22;

int p[S];
long double logs[2][1 << N];
int ids[2][1 << N];
vector<int> primes;
vector<int> parts[2];
vector<vector<int>> masks[2];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i < S; i ++) {
        if (p[i]) continue;
        primes.push_back(i);
        for (int j = i + i; j < S; j += i) {
            p[j] = 1;
        }
    }
    int N = (int)primes.size();
    long double allLog = 0.;
    for (int i = 0; i < N; i ++) {
        allLog += 1. * logl(primes[i]);
        if (i + i < N) {
            parts[0].push_back(primes[i]);
        } else {
            parts[1].push_back(primes[i]);
        }
    }
    for (int i = 0; i < 2; i ++) {
        int l = (int)parts[i].size();
        for (int j = 0; j < (1 << l); j ++) {
            ids[i][j] = j;
            for (int k = 0; k < l; k ++) {
                if (j & (1 << k)) {
                    logs[i][j] = logs[i][j ^ (1 << k)] + logl(1. * parts[i][k]);
                    break;
                }
            }
        }
        sort(ids[i], ids[i] + (1 << l), [&](int a, int b) {
            return logs[i][a] < logs[i][b];
        });
    }
    int best1 = 0, best2 = 0;
    long double bestLog = 0.;
    int l1 = (1 << (int)parts[0].size()) - 1;
    int l2 = (1 << (int)parts[1].size()) - 1;
    for (int i = 0; i < l1; i ++) {
        while (l2 >= 0 && 2. * (logs[0][ids[0][i]] + logs[1][ids[1][l2]]) >= allLog) {
            l2 --;
        }
        if (l2 >= 0 && 2. * (logs[0][ids[0][i]] + logs[1][ids[1][l2]]) < allLog) {
            long double currentSum = logs[0][ids[0][i]] + logs[1][ids[1][l2]];
            if (currentSum > bestLog) {
                bestLog = currentSum;
                best1 = ids[0][i];
                best2 = ids[1][l2];
            }
        }
    }
    unsigned long long result = 1;
    long long modulo = 10000000000000000LL;
    for (int i = 0; i < (int)parts[0].size(); i ++) {
        if (best1 & (1 << i)) {
            //cout << "factor: " << parts[0][i] << endl;
            result = result * parts[0][i] % modulo;
        }
    }
    for (int i = 0; i < (int)parts[1].size(); i ++) {
        if (best2 & (1 << i)) {
            //cout << "factor: " << parts[1][i] << endl;
            result = result * parts[1][i] % modulo;
        }
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

