//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/17/18.
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

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a >= b) a %= b;
        else b %= a;
    }
    return a + b;
}

long long f[100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    /*
     2 * a * (a - 1) = b * (b - 1)
     oeisable: http://oeis.org/search?q=4%2C+21%2C+120%2C+697&sort=&language=english&go=Search
     */
    
    for (int i = 1; i < 30000; i ++) {
        for (int j = 1; j < i; j ++) {
            if (2 * j * (j - 1) == i * (i - 1)) {
                cout << i << " " << j << " --> ";
                int x = gcd(i, j);
                cout << i / x << " " << j / x << endl;
            }
        }
    }
    long long now = -1;
    f[0] = 1;
    f[1] = 4;
    for (int i = 2; i < 100; i ++) {
        f[i] = 6LL * f[i - 1] - f[i - 2] - 2;
        cout << i << " " << f[i] << endl;
        if (f[i] >= 1000000000000LL) {
            now = f[i];
            break;
        }
    }
    cerr << now << endl;
    
    long long low = 0, high = now, middle, best = low;
    while (low <= high) {
        middle = (low + high + 1) / 2;
        if (1. * now * (now - 1) - 2. * middle * (middle - 1) > 1.e-10) {
            best = middle;
            low = middle + 1;
        }
        else {
            high = middle - 1;
        }
    }
    cout << best << endl;
    
    return 0;
}
