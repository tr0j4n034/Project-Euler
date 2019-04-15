//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/11/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <bitset>
#include <cassert>

using namespace std;

const int MAX = 12005;

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    long long result = 0;
    int N = 1000000;
    for (int i = 1; i <= N; i ++) {
        for (int j = i - 2; j > 0; j -= 2) {
            if (1LL * i * i - 1LL * j * j > N) break;
            else result ++;
        }
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
