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

const int MAX = 1000001;

int power(int a, int b, int modulo) {
    if (b == 0) return 1 % modulo;
    if (b & 1) return 1LL * power(a, b - 1, modulo) * a % modulo;
    return power(1LL * a * a % modulo, b >> 1, modulo);
}

int main() {
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;

    long long result = 0;
    for (int i = 3; i <= 1000; i ++) {
        int x = 0;
        for (int j = 1; j <= 4444; j ++) {
            int now = (power(i - 1, j, i * i) + power(i + 1, j, i * i)) % (i * i);
            x = max(x, now);
        }
        result += x;
    }
    cout << result << endl;
    
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
