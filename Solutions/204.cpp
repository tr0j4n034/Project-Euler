//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/13/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <bitset>
#include <cassert>
#include <numeric>
#include <functional>

using namespace std;

const int MAX = 15;

vector<int> p;

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i < 100; i ++) {
        int g = 1;
        for (int j = 2; j * j <= i; j ++) {
            if (i % j == 0) {
                g = 0;
                break;
            }
        }
        if (g) p.push_back(i);
    }
    cerr << (int)p.size() << endl;
    
    int result = 0;
    for (int i = 1; i <= 1000000000; i ++) {
        int j = i;
        for (int k : p) {
            while (j % k == 0) j /= k;
        }
        if (j == 1) result ++;
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
