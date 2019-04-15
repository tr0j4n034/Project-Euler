//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/4/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#pragma GCC optimize("-0g")

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <ctime>

using namespace std;

const int MAX = 105;

long long p = 0;

int good(int a, int b) {
    if (b & 1) return 0;
    long long x = 1LL * a * a - 1LL * b * b / 4;
    int root = int(sqrt(x + 1.e-10));
    if (1LL * root * root != x) return 0;
    if (1LL * root * b / 2 % 2 == 1) return 0;
    return 1;
}

int main() {
    for (int i = 2; i + i + i + 1 <= 1000000000; i ++) {
        //if (good(i, i - 1)) cout << i << " " << i - 1 << endl;
        //if (good(i, i + 1)) cout << i << " " << i + 1 << endl;
        if (good(i, i - 1)) p += i + i + i - 1;
        if (good(i, i + 1)) p += i + i + i + 1;
    }
    cout << p << endl;
    
    return 0;
}

