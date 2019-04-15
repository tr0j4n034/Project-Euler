//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/4/18.
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

using namespace std;

const int MAX = 50;

map<pair<int, int>, set<pair<int, int>>> m;

int main() {
    for (int i = 0; i <= 50; i ++) {
        for (int j = 0; j <= 50; j ++) {
            for (int k = 0; k <= 50; k ++) {
                for (int q = 0; q <= 50; q ++) {
                    int d1 = (i - k) * (i - k) + (j - q) * (j - q);
                    int d2 = i * i + j * j;
                    int d3 = k * k + q * q;
                    if (d1 == 0 || d2 == 0 || d3 == 0) continue;
                    if (d1 + d2 == d3 || d1 + d3 == d2 || d2 + d3 == d1) {
                        pair<int, int> f = make_pair(i, j);
                        pair<int, int> s = make_pair(k, q);
                        if (f > s) swap(f, s);
                        m[f].insert(s);
                    }
                }
            }
        }
    }
    int result = 0;
    for (auto i : m) result += (int)i.second.size();
    
    cout << result << endl;
    
    return 0;
}

