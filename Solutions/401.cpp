//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/23/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

const long long S = 1000000000000000LL;
const int MODULO = 1000000000;

long long brute(long long N) {
    long long sum = 0;
    for (int i = 1; i <= N; i ++) {
        sum += 1LL * i * i * (N / i);
        sum %= MODULO;
    }
    return sum;
}
long long multiply(long long a, long long b, long long c, long long divider = 6) {
    if (a % 2 == 0) {
        a /= 2;
        divider /= 2;
    }
    if (a % 3 == 0) {
        a /= 3;
        divider /= 3;
    }
    if (divider % 2 == 0 && b % 2 == 0) {
        b /= 2;
        divider /= 2;
    }
    if (divider % 3 == 0 && b % 3 == 0) {
        b /= 3;
        divider /= 3;
    }
    if (divider % 2 == 0 && c % 2 == 0) {
        c /= 2;
        divider /= 2;
    }
    if (divider % 3 == 0 && c % 3 == 0) {
        c /= 3;
        divider /= 3;
    }
    a %= MODULO;
    b %= MODULO;
    c %= MODULO;
    return a * b % MODULO * c % MODULO;
}
long long solve(long long N) {
    long long sum = 0;
    long long last = 0;
    for (int i = 1; 1LL * i * i <= S; i ++) {
        sum += 1LL * i * i % MODULO * ((S / i) % MODULO);
        sum %= MODULO;
        last = i;
    }
    last ++;
    for (int i = (int)last; i > 0; i --) {
        long long to = S / i;
        //cout << "at i = " << i << ", last = " << last << " " << to << endl;
        if (last > to) continue;
        //long long c = to * (to + 1) * (2 * to + 1) / 6 - (last - 1) * last * (2 * last - 1) / 6;
        long long c = multiply(to, to + 1, 2 * to + 1) - multiply(last - 1, last, 2 * last - 1);
        if (c < 0) c += MODULO;
        sum += c * i;
        sum %= MODULO;
        last = to + 1;
    }
    return sum;
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    //cout << brute(S) << endl;
    cout << solve(S) << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

