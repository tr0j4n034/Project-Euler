//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/15/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>

using namespace std;

int N;
int a[9];
vector<int> candidates;

int main() {
    auto f = [&](int *a) {
        int s = 0;
        for (int i = 0; i < N; i ++) s = 10 * s + a[i];
        return s;
    };
    auto isPrime = [&](int x) {
        if (x < 2) return 0;
        for (int i = 2; i * i <= x; i ++) {
            if (x % i == 0) return 0;
        }
        return 1;
    };
    
    N = 7;
    
    iota(a, a + N, 1);
    do {
        candidates.push_back(f(a));
    } while (next_permutation(a, a + N));
    sort(candidates.begin(), candidates.end(), greater<int>());
    
    for (auto i : candidates) {
        if (isPrime(i)) {
            cout << i << endl;
            return 0;
        }
    }
    
    
    return 0;
}
