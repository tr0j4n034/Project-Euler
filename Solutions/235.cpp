//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/07/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 5005;

long double u[MAX];
long double sum[MAX];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    long double low = 0., high = 5., middle;
    for (int it = 0; it < 180; it ++) {
        middle = (low + high) / 2.;
        long double r = middle;
        for (int i = 1; i <= 5000; i ++) {
            u[i] = (900. - 3. * i) * powl(r, 1. * i - 1);
            sum[i] = sum[i - 1] + u[i];
            //            cout << i << " vs " << u[i] << " --> " << sum[i] << endl;
        }
        if (sum[5000] <= -6e11) {
            high = middle;
        }
        else {
            low = middle;
        }
        cout.precision(13);
        cout << "middle = " << fixed << middle << " --> " << fixed << sum[5000] << endl;
    }
    cout.precision(13);
    cout << low << endl;
    
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
