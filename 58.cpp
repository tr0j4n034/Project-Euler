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

const int MAX = 10000005;

int isPrime(int N) {
    for (int i = 2; i * i <= N; i ++) {
        if (N % i == 0) return 0;
    }
    return N != 1 ? 1 : 0;
}

int main() {
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    int c = 1, cx = 30000, cy = 30000, x = cx, y = cy, steps = 2, r = 1, s = 1;
    int primes = 0, all = 0;
    for (int i = 1; i < MAX; i ++) {
        if (abs(x - cx) == abs(y - cy)) {
            //cout << "in 1: " << c << endl;
            all ++;
            primes += isPrime(c);
        }
        if (s > 1 && primes * 10 < all) {
            cout << s << endl;
            return 0;
        }
        if (c + steps - 2 != 1) {
            all ++;
            primes += isPrime(c + steps - 2);
        }
        //cout << c + steps - 2 << endl;
        c += steps;
        x += steps - 1;
        c --;
        r ++;
        if (abs(x - cx) == abs(y - cy)) {
            //cout << "in 2: " << c << endl;
            all ++;
            primes += isPrime(c);
        }
        if (s > 1 && primes * 10 < all) {
            cout << s << endl;
            return 0;
        }
        c += steps;
        y -= steps - 1;
        c --;
        r ++;
        s ++;
        if (abs(x - cx) == abs(y - cy)) {
            //cout << "in 3: " << c << endl;
            all ++;
            primes += isPrime(c);
        }
        if (s > 1 && primes * 10 < all) {
            cout << s << endl;
            return 0;
        }
        steps ++;
        c += steps;
        x -= steps - 1;
        c --;
        r ++;
        if (abs(x - cx) == abs(y - cy)) {
            //cout << "in 4: " << c << endl;
            all ++;
            primes += isPrime(c);
        }
        if (s > 1 && primes * 10 < all) {
            cout << s << endl;
            return 0;
        }
        c += steps;
        y += steps - 1;
        c --;
        r ++;
        steps ++;
        s ++;
    }
    cout << "all: " << all << endl;
    cout << "p: " << primes << endl;
    
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
