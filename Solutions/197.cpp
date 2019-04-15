//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/20/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int S = 1000;

long double u[S];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    auto f = [](long double x) {
        return floor(powl(2., 30.403243784 - x * x)) * 1.e-9;
    };
    for (int i = 0; i < S; i ++) {
        if (i == 0) u[i] = -1;
        else u[i] = f(u[i - 1]);
        
        long double sum = u[i];
        if (i > 0) sum += u[i - 1];
        cout.precision(10);
        cout << i << " --> " << fixed << u[i] << ", sum = " << fixed << sum << endl;
    }
    
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

