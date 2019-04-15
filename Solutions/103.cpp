//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/3/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

const int N = 7;
//int a[] = {11, 18, 19, 20, 22, 25};
int b[] = {20, 11 + 20, 18 + 20, 19 + 20, 20 + 20, 22 + 20, 25 + 20};
int bits[1 << N];
int c[N], sum[1 << 10];

string result;

void go(vector<int> deltas) {
    if ((int)deltas.size() == N) {
        for (int i = 0; i < N; i ++) c[i] = b[i] + deltas[i];
        sort(c, c + N);
        for (int i = 0; i < (1 << N); i ++) {
            for (int j = 0; j < N; j ++) {
                if (i & (1 << j)) {
                    sum[i] = sum[i ^ (1 << j)] + c[j];
                    break;
                }
            }
        }
        bool good = true;
        for (int i = 0; i < (1 << N) && good; i ++) {
            for (int j = i + 1; j < (1 << N) && good; j ++) {
                if (i != j && sum[i] == sum[j]) {
                    good = false;
                }
                if (bits[i] > bits[j] && sum[i] <= sum[j]) {
                    good = false;
                }
            }
        }
        if (good) {
            string now = "";
            for (int i = 0; i < N; i ++) {
                now += to_string(c[i]);
            }
            if (result == "" || result > now) {
                result = now;
            }
        }
        return;
    }
    for (int i = -4; i < +4; i ++) {
        vector<int> current = deltas;
        current.push_back(i);
        go(current);
    }
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < (1 << N); i ++) {
        for (int j = 0; j < N; j ++) {
            if (i & (1 << j)) {
                bits[i] = bits[i ^ (1 << j)] + 1;
                break;
            }
        }
    }
    
    go(vector<int>());
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
