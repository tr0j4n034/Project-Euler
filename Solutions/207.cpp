//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/16/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

const int S = 10000001;

map<long long, int> perfect;

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int t = 1; t < 30; t ++) {
        perfect[(1LL << (t << 1)) - (1LL << t)] ++;
    }
    int numerator = 0, denominator = 0;
    for (long long i = 2, j = 4; ; i += j, j += 2) {
        if (perfect.count(i)) numerator ++;
        denominator ++;
        cout << i << " " << numerator << " " << denominator << endl;
        if (12345LL * numerator < denominator) {
            cout << "found at i = " << i << endl;
            return 0;
        }
    }
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

