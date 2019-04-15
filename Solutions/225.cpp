//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/22/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

const int S = 100001;

int f[S], was[S];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    int need = 124;
    f[1] = f[2] = f[3] = 1;
    
    for (int i = 3; i < S; i += 2) {
        if (was[i]) continue;
        bool can = false;
        for (int j = 4; j < S; j ++) {
            f[j] = (f[j - 1] + f[j - 2] + f[j - 3]) % i;
            if (f[j] == 0) {
                can = true;
                break;
            }
        }
        if (!can) {
            --need;
            if (need == 0) {
                cout << "found i = " << i << endl;
                break;
            }
        }
    }
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

