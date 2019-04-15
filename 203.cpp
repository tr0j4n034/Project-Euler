//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/6/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#pragma GCC optimize("-0g")

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <utility>
#include <cassert>

using namespace std;

const int MAX = 55;

long long c[MAX][MAX];
set<long long> s;

int main() {
    for (int i = 0; i <= 50; i ++) {
        for (int j = 0; j <= 50; j ++) {
            if (i < j) continue;
            if (i == 0 || j == 0) c[i][j] = 1;
            else c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            s.insert(c[i][j]);
        }
    }
    long long sum = 0;
    for (auto i : s) {
        sum += i;
        for (int j = 2; j <= 100; j ++) {
            if (i % (j * j) == 0) {
                sum -= i;
                break;
            }
        }
    }
    cout << sum << endl;
    
    return 0;
}
