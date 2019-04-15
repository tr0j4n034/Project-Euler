//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/07/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAX = 1000000;

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    int ways = 0;
    for (int i = 0; i < (1 << 10); i ++) {
        for (int j = i; j < (1 << 10); j ++) {
            int bits1 = 0, bits2 = 0;
            for (int k = 0; k < 10; k ++) {
                if (i & (1 << k)) bits1 ++;
                if (j & (1 << k)) bits2 ++;
            }
            if (bits1 != 6 || bits2 != 6) continue;
            int mask1 = i;
            int mask2 = j;
            if ((mask1 & (1 << 6)) || (mask1 & (1 << 9))) {
                mask1 |= (1 << 6);
                mask1 |= (1 << 9);
            }
            if ((mask2 & (1 << 6)) || (mask2 & (1 << 9))) {
                mask2 |= (1 << 6);
                mask2 |= (1 << 9);
            }
            int good = 0;
            for (int k = 1; k < 10; k ++) {
                int l = (k * k) / 10;
                int r = (k * k) % 10;
                good = 0;
                if ((mask1 & (1 << l)) && (mask2 & (1 << r))) {
                    good = 1;
                }
                if ((mask1 & (1 << r)) && (mask2 & (1 << l))) {
                    good = 1;
                }
                if (!good) break;
            }
            if (good) {
                ways ++;
            }
        }
    }
    cout << ways << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
