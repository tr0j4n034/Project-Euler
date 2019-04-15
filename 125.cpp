//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/6/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#pragma GCC optimize("-0g")

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <utility>
#include <cassert>

using namespace std;

const int MAX = 11111;

int get(int N) {
    int s = 0;
    while (N > 0) {
        s = 10 * s + N % 10;
        N /= 10;
    }
    return s;
}

map<long long, int> important;

int main() {
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;

    for (int i = 0; i < MAX; i ++) {
        important[1LL * i * (i + 1) * (2 * i + 1) / 6] = i;
    }
    long long sum = 0;
    for (int i = 2; i < 100000000; i ++) {
        if (i != get(i)) continue;
        for (int j = 1; j < MAX; j ++) {
            long long now = 1LL * j * (j + 1) * (2 * j + 1) / 6;
            if (important.count(now - i) && important[now - i] != j - 1) {
                //cout << i << endl;
                sum += i;
                break;
            }
        }
    }
    cout << sum << endl;
    
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
