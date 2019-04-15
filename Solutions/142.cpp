//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/14/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

const int MAX = 1000005;

set<int> can[MAX];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i * i < MAX; i ++) {
        for (int j = 1; j < i; j ++) {
            int sum = i * i + j * j;
            if (sum % 2) continue;
            int x = sum / 2;
            int y = i * i - x;
            if (x > 0 && y > 0 && x < MAX && y < MAX) {
                can[x].insert(y);
            }
        }
    }
    for (int i = 1; i < MAX; i ++) {
        for (int j: can[i]) {
            int match = 0;
            for (int k: can[i]) {
                if (can[j].count(k)) {
                    match = 1;
                    cout << i << " " << j << " " << k << endl;
                    cout << "sum = " << i + j + k << endl;
                    break;
                }
            }
            if (match) return 0;
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
