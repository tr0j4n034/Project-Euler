//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/5/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
#include <ctime>

using namespace std;

const int N = 100000000;

int lp[N];
long long result = 0;

void go(vector<pair<int, int>> &divisors, int step, long long product, int number, long long all) {
    if (step == (int)divisors.size()) {
        if (product < number && all / product > number && all / product < N) {
            if (lp[product - 1] == product - 1 && lp[all / product - 1] == all / product - 1) {
                result += number - 1 + product - 1 + all / product - 1;
                //cout << product - 1 << " " << number - 1 << " " << all / product - 1 << endl;
            }
        }
        return;
    }
    long long p = product;
    for (int i = 0; i <= 2 * divisors[step].second; i ++) {
        go(divisors, step + 1, p, number, all);
        p *= divisors[step].first;
        if (p > N) break;
    }
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i < N; i ++) lp[i] = i;
    for (int i = 2; i * i < N; i ++) {
        if (lp[i] != i) continue;
        for (int j = i * i; j < N; j += i) {
            lp[j] = i;
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i < N; i ++) {
        if (lp[i] != i) continue;
        //if (i != 5) continue;
        vector<pair<int, int>> v;
        int j = i + 1;
        while (j > 1) {
            int d = lp[j];
            v.push_back(make_pair(d, 0));
            while (j % d == 0) {
                j /= d;
                v.back().second ++;
            }
        }
        //for (auto j: v) cout << j.first << " " << j.second << endl;
        go(v, 0, 1, i + 1, 1LL * (i + 1) * (i + 1));
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

