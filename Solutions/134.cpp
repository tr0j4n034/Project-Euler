//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/02/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <bitset>
#include <cassert>

using namespace std;

const int MAX = 30000005;
const int PMAX = 1000000;

int pw[8];
int p[MAX];

int getSize(int N) {
    int s = 0;
    while (N > 0) {
        s ++;
        N /= 10;
    }
    return s;
}
int power(int a, int b, int modulo) {
    if (b == 0) return 1 % modulo;
    if (b & 1) return 1LL * a * power(a, b - 1, modulo) % modulo;
    return power(1LL * a * a % modulo, b >> 1, modulo);
}
int inverse(int a, int modulo) {
    return power(a, modulo - 2, modulo);
}
int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a >= b) a %= b;
        else b %= a;
    }
    return a + b;
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 0; i < 8; i ++) {
        if (i == 0) pw[i] = 1;
        else pw[i] = pw[i - 1] * 10;
    }
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        for (int j = i + i; j < MAX; j += i) {
            p[j] = 1;
        }
    }
    int last = 5;
    unsigned long long result = 0;
    for (int i = 6; last <= PMAX; i ++) {
        if (p[i]) continue;
        int multiplier = pw[getSize(last)], m = multiplier;
        int rhs = i - last;
        int g = gcd(multiplier, rhs);
        //multiplier /= g;
        //rhs /= g;
        int inv = inverse(multiplier, i);
        int now = 1LL * rhs * inv % i;
        //        if (i == 23) cout << now << endl;
        if (i < 30) cout << last << " " << i << " --> " << m * now + last << ", rhs = " << rhs << " and inv = " << inv << ", mul = " << multiplier << endl;
        assert(m != 0);
        assert((1LL * m * now + last) % i == 0);
        result += (1LL * m * now + last);
        last = i;
        //        int f = -1;
        //        for (int j = 1; j < 1000000; j ++) {
        //            if ((1LL * j * multiplier + last) % i == 0) {
        //                f = j * multiplier + last;
        //                break;
        //            }
        //        }
        //        last = i;
        //        assert(f != -1);
        //        result += f;
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

