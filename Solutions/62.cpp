//
//  main.cpp
//  practice
//
//  Created by Mahmud on 04/30/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MAX = 1005;

map<string, int> m;
map<string, vector<long long>> p;

int main() {
    for (int i = 1; i < 20000; i ++) {
        long long now = 1LL * i * i * i;
        string s = to_string(now);
        sort(s.begin(), s.end());
        m[s] ++;
        p[s].push_back(now);
    }
    for (auto i : m) {
        if (i.second > 4) {
            for (auto j : p[i.first]) cout << j << endl;
            return 0;
        }
    }
    
    return 0;
}
