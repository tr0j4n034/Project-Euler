//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/10/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;

int ways[MAX];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < MAX; i ++) {
        for (int j = i - 2; j > 0; j -= 2) {
            long long tiles = 1LL * i * i - 1LL * j * j;
            if (tiles > MAX) break;
            ways[tiles] ++;
        }
    }
    int s = 0;
    for (int i = 1; i <= MAX; i ++) {
        if (ways[i] > 0 && ways[i] <= 10) s ++;
    }
    cout << s << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
