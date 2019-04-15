//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/14/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a >= b) a %= b;
        else b %= a;
    }
    return a + b;
}

int main() {
    int l = 1, r = 1;
    for (int i = 10; i < 100; i ++) {
        for (int j = i + 1; j < 100; j ++) {
            int i1 = i / 10, i2 = i % 10;
            int j1 = j / 10, j2 = j % 10;
            if(i1 == i2 || j1 == j2) continue;
            if (i2 == 0 || j2 == 0) continue;
            if (i2 != j1) continue;
            if (i * j2 == j * i1) {
                //cout << i << " vs " << j << endl;
                l *= i;
                r *= j;
            }
        }
    }
    int g = gcd(l, r);
    l /= g;
    r /= g;
    cout << r << endl;
    
    return 0;
}
