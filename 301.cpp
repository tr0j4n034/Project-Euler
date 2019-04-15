//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/18/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <cassert>

using namespace std;

const int MAX = 100001;

int dp[35][2];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    /// oeisable: http://oeis.org/search?q=42%2C+64%2C+65%2C+66%2C+68%2C+69%2C+72%2C+73&sort=&language=english&go=Search
    
    dp[1][1] = 1;
    for (int i = 2; i <= 30; i ++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
    int result = 0;
    for (int i = 1; i <= 30; i ++) {
        result += dp[i][0] + dp[i][1];
    }
    cout << result + 1 << endl;
    
    return 0;
    
    for (int i = 1; i < 100; i ++) {
        int x = i ^ (i * 2) ^ (i * 3);
        if (x == 0) cout << i << " ";
        else continue;
        int g = 1;
        for (int j = 0; j < 10; j ++) {
            if ((i & (1 << j)) && (i & (1 << (j + 1)))) g = 0;
        }
        if (g) cout << i << endl;
        else cout << "-" << endl;
    }
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
