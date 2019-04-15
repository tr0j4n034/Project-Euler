//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/29/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 1 << 19;
const int MODULO = 1000000000;

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    int a = 1, b = 1, c;
    long double phi = (sqrtl(5.) + 1.) / 2.;
    
    for (int i = 3; i < N; i ++) {
        c = (a + b) % MODULO;
        a = b;
        b = c;
        string cn = to_string(c);
        sort(cn.begin(), cn.end());
        int good = (int)cn.size() == 9;
        for (int j = 0; j < 9 && good; j ++) {
            good &= cn[j] == '1' + j;
        }
        if (!good) continue;
        cout << i << " is good" << endl;
        long double lg = 1. * (long double)i * log10(phi) - 0.5 * log10(5.);
        long double st = fmod(lg, 10.);
        long double value = powl(10., st);
        long long now = (long long)(round)(value);
        string wn = to_string(now);
        sort(wn.begin(), wn.end());
        if (i == 329468) {
            cout.precision(10);
            cout << i << " --> " << wn << " " << fixed << value << endl;
            break;
        }
        int delta = 0;
        for (int j = 0; j < 9 && good; j ++) {
            delta += (int)(wn[j] != '1' + j);
        }
        if (delta > 2) continue;
        
        cout << i << " is best" << endl;
    }
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

