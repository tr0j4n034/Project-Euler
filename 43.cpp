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

int N = 10;
int a[10];

int main() {
    auto f = [&](int *a, int l, int r) {
        long long s = 0;
        for (int i = l; i <= r; i ++) s = 10 * s + a[i];
        return s;
    };

    long long sum = 0;
    iota(a, a + N, 0);
    do {
        if (f(a, 1, 3) % 2) continue;
        if (f(a, 2, 4) % 3) continue;
        if (f(a, 3, 5) % 5) continue;
        if (f(a, 4, 6) % 7) continue;
        if (f(a, 5, 7) % 11) continue;
        if (f(a, 6, 8) % 13) continue;
        if (f(a, 7, 9) % 17) continue;
        cout << f(a, 0, N - 1) << endl;
        sum += f(a, 0, N - 1);
    } while (next_permutation(a, a + N));
    cout << sum << endl;
    
    return 0;
}
