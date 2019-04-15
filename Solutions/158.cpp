//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/15/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAX = 1 << 26;

int bitCount[MAX];
long long counts[27], ways[27];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < MAX; i ++) {
        bitCount[i] = bitCount[i - (i & -i)] + 1;
        counts[bitCount[i]] ++;
    }
    long long best = 0;
    for (int i = 1; i <= 26; i ++) {
        ways[i] = 1LL * counts[i] * ((1 << i) - i - 1);
        cerr << i << " " << ways[i] << " " << counts[i] << endl;
        if (ways[i] > best) {
            best = ways[i];
        }
    }
    cout << "best = " << best << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
