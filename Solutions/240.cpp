//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/21/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int FACES = 12;
const int N = 20;
const int M = 10;
const int TOPSUM = 70;

map<vector<int>, long long> ways[N + 1];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i <= FACES; i ++) {
        ways[1][vector<int>(1, i)] ++;
    }
    for (int i = 1; i < N; i ++) {
        cout << "now at i = " << i << endl;
        for (auto data: ways[i]) {
            for (int j = 1; j <= FACES; j ++) {
                vector<int> now = data.first;
                now.push_back(j);
                sort(now.begin(), now.end());
                while ((int)now.size() > M) {
                    now.erase(now.begin());
                }
                ways[i + 1][now] += data.second;
            }
        }
        ways[i].clear();
    }
    long long result = 0;
    for (auto i: ways[N]) {
        int topsum = 0;
        for (auto j: i.first) {
            topsum += j;
        }
        if (topsum == TOPSUM) {
            result += i.second;
        }
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

