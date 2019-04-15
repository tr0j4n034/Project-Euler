//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/18/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

const int S = 1000;

long double factorial[S + 1];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    factorial[0] = 1.;
    for (int i = 1; i <= S; i ++) {
        factorial[i] = factorial[i - 1] * i;
    }
    
    auto getMinWinning = [](long double f, long double amount = 1e9, int flips = 1000) {
        long double win = 1. + 2. * f;
        long double lose = 1. - f;
        long double low = 0., high = 1. * flips, middle;
        for (int it = 0; it < 70; it ++) {
            middle = (low + high) / 2.;
            long double current = middle * log(win) + (1. * flips - middle) * log(lose);
            if (current >= log(amount)) {
                high = middle;
            }
            else {
                low = middle;
            }
        }
        return low;
    };
    
    long double low = 0., high = 1.;
    
    for (int it = 0; it < 70; it ++) {
        long double middle1 = (low + low + high) / 3.;
        long double middle2 = (low + high + high) / 3.;
        if (getMinWinning(middle1) > getMinWinning(middle2)) {
            low = middle1;
        }
        else {
            high = middle2;
        }
    }
    cout.precision(12);
    cout << fixed << low << " " << high << endl;
    
    long double p = 0.;
    for (int i = 0; i <= S; i ++) {
        long double win = 1. + 2 * low;
        long double lose = 1. - low;
        long double current = i * log(win) + (1. * S - i) * log(lose);
        if (current >= log(1e9)) {
            p += factorial[S] / factorial[i] / factorial[S - i] / powl(2., S);
        }
    }
    cout.precision(12);
    cout << fixed << p << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
