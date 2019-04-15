//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/10/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 50000000;

int ways[MAX];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < MAX; i ++) {
        for (int j = i, k = 1; j < MAX; j += i, k ++) {
            if ((i + k) % 4 == 0) {
                int d = (i + k) / 4;
                int z = 3 * d - i;
                if (z > 0) ways[j] ++;
            }
        }
    }
    int s = 0;
    for (int i = 1; i < MAX; i ++) {
        if (ways[i] == 1) {
            s ++;
        }
    }
    cout << s << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
