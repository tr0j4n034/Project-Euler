//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/10/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 5000;
const int UP = 1600000;
const long long MODULO = 100000000000000000LL;

int p[UP];
vector<int> primes;
long long dp[UP], temp[UP];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i < UP; i ++) {
        if (p[i]) continue;
        if (i < MAX) {
            primes.push_back(i);
        }
        for (int j = i + i; j < UP; j += i) {
            p[j] = 1;
        }
    }
    int sum = 0;
    for (int i: primes) sum += i;
    
    for (int i: primes) {
        for (int j = 0; j <= sum; j ++) temp[j] = dp[j];
        for (int j = sum; j > i; j --) {
            dp[j] = (dp[j] + temp[j - i]) % MODULO;
        }
        dp[i] = (dp[i] + 1) % MODULO;
    }
    long long result = 0;
    for (int i = 2; i < UP; i ++) {
        if (!p[i]) {
            result = (result + dp[i]) % MODULO;
        }
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
