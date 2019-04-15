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

const int MAX = 10000001;

int g[MAX];
pair<int, int> p[MAX];
set<pair<int, int>> s;

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i < MAX; i ++) {
        if (p[i].first != 0) continue;
        for (int j = i; j < MAX; j += i) {
            if (g[j] == -1) continue;
            if (p[j].second != 0) {
                g[j] = -1;
            }
            else if (!p[j].first) p[j].first = i;
            else p[j].second = i;
        }
    }
    long long result = 0;
    for (int i = MAX - 1; i > 0; i --) {
        if (g[i] == -1 || p[i].second == 0) continue;
        if (s.count(make_pair(p[i].first, p[i].second))) continue;
        result += i;
        s.insert(make_pair(p[i].first, p[i].second));
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
