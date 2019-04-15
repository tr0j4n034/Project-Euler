//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/3/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <ctime>

using namespace std;

const int N = 15;
const int M = 8;

int valid[1 << N];
vector<int> masks;
map<pair<int, int>, long long> dp[M + 1];

bool intersects(int top, int down) {
    for (int i = 1; i < N; i += 2) {
        if (down & (1 << i)) {
            if (top & (1 << (i - 1))) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    dp[1][make_pair(1, 0)] ++;
    dp[1][make_pair(0, 1)] ++;
    dp[1][make_pair(0, 0)] ++;
    
    for (int i = 0; i < (1 << N); i ++) {
        valid[i] = 1;
        for (int j = 1; j < N; j ++) {
            if (i & (1 << j)) {
                if (i & (1 << (j - 1))) {
                    valid[i] = 0;
                    break;
                }
            }
        }
        if (valid[i]) masks.push_back(i);
    }
    for (int i = 2; i <= M; i ++) {
        int all = (1 << (i + i - 1)) - 1;
        for (int red: masks) {
            if (red > all) break;
            for (int green: masks) {
                if (green > all) break;
                if (red & green) continue;
                if (!valid[all ^ red ^ green]) continue;
                int blue = all ^ red ^ green;
                for (auto state: dp[i - 1]) {
                    int oldred = state.first.first;
                    int oldgreen = state.first.second;
                    int oldblue = ((1 << (i + i - 3)) - 1) ^ oldred ^ oldgreen;
                    if (intersects(oldred, red)) continue;
                    if (intersects(oldgreen, green)) continue;
                    if (intersects(oldblue, blue)) continue;
                    dp[i][make_pair(red, green)] += state.second;
                }
            }
        }
    }
    long long result = 0;
    for (auto i: dp[M]) {
        //cout << i.first.first << " " << i.first.second << " --> " << i.second << endl;
        result += i.second;
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
