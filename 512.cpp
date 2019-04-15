//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/24/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int S = 500000000 + 1;

int lp[S], phi[S];

int power(int a, int b, int modulo) {
    int result = 1, p = a;
    while (b) {
        if (b & 1) {
            result = 1LL * result * p % modulo;
        }
        b >>= 1;
        p = 1LL * p * p % modulo;
    }
    return result;
}
int inverse(int a, int modulo) {
    return power(a, modulo - 2, modulo);
}
int sum(int base, int n, int modulo) {
    if (n == 0) {
        return 1;
    } else if (n & 1) {
        return 1LL * sum(base, n >> 1, modulo) * (power(base, (n + 1) >> 1, modulo) + 1) % modulo;
    } else {
        return (sum(base, n - 1, modulo) + power(base, n, modulo)) % modulo;
    }
}

int main() {
    for (int i = 1; i < S; i ++) {
        lp[i] = i;
    }
    phi[1] = 1;
    for (int i = 2; i * i < S; i ++) {
        if (lp[i] != i) {
            continue;
        }
        for (int j = i * i; j < S; j += i) {
            lp[j] = i;
        }
    }
    for (int i = 2; i < S; i ++) {
        int d = lp[i];
        int j = i / d;
        if (j % d == 0) {
            phi[i] = phi[j] * d;
        } else {
            phi[i] = phi[j] * (d - 1);
        }
    }
    long long result = 0;
    for (int i = 1; i < S; i ++) {
        //result = (result + 1LL * phi[i] * sum(i, i - 1, i + 1) % (i + 1));
        if (i & 1) {
            result += phi[i];
        }
    }
    cout << result << endl;
    
    return 0;
}

