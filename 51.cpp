//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/22/18.
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
#include <utility>
#include <bitset>
#include <cassert>

using namespace std;

const int MAX = 1000005;

int p[MAX];
map<string, int> m;
map<string, int> id;

int getSize(int N) {
    int s = 0;
    while (N > 0) {
        s ++;
        N /= 10;
    }
    return s;
}

int main() {
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        for (int j = i + i; j < MAX; j += i) {
            p[j] = 1;
        }
    }
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        int l = getSize(i);
        string s = to_string(i);
        for (int j = 0; j < (1 << l); j ++) {
            set<char> cnt;
            for (int k = 0; k < l; k ++) {
                if (j & (1 << k)) {
                    cnt.insert(s[k]);
                }
                if ((int)cnt.size() > 1) break;
            }
            if ((int)cnt.size() == 1) {
                string now = "";
                for (int k = 0; k < l; k ++) {
                    if (j & (1 << k)) {
                        now += '*';
                    }
                    else {
                        now += s[k];
                    }
                }
                m[now] ++;
                if (!id.count(now) || id[now] > i) {
                    id[now] = i;
                }
            }
        }
    }
    for (auto i : m) {
        if (i.second == 8) {
            cout << id[i.first] << endl;
            
        }
    }
    
    return 0;
}
