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

const int MAX = 4000005;

const int N = 2000;

int a[N][N];
int s[MAX];

int main() {
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i <= N * N; i ++) {
        if (i <= 55) {
            s[i] = (100003 - 200003LL * i % 1000000
                    + 300007LL * i % 1000000 * i % 1000000 * i % 1000000) % 1000000 - 500000;
        }
        else {
            s[i] = (s[i - 24] + s[i - 55] + 4000000) % 1000000 - 500000;
        }
    }
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    cerr << s[10] << " " << s[100] << endl;
    
    for (int i = 1; i <= N * N; i ++) {
        a[(i - 1) / N][(i - 1) % N] = s[i];
    }
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    long long best = 0;
    for (int i = 0; i < N; i ++) {
        int a = i, b = 0;
        for (int dx = -1; dx < 2; dx ++) {
            for (int dy = -1; dy < 2; dy ++) {
                if (dx * dx + dy * dy == 0) continue;
                int x = a, y = b;
                long long current = 0;
                while (x >= 0 && y >= 0 && x < N && y <= N) {
                    long long now = max(current + ::a[x][y], 1LL * ::a[x][y]);
                    best = max(best, now);
                    current = max(now, 0LL);
                    x += dx;
                    y += dy;
                }
            }
        }
        a = 0;
        b = i;
        for (int dx = -1; dx < 2; dx ++) {
            for (int dy = -1; dy < 2; dy ++) {
                if (dx * dx + dy * dy == 0) continue;
                int x = a, y = b;
                long long current = 0;
                while (x >= 0 && y >= 0 && x < N && y < N) {
                    long long now = max(current + ::a[x][y], 1LL * ::a[x][y]);
                    best = max(best, now);
                    current = max(now, 0LL);
                    x += dx;
                    y += dy;
                }
            }
        }
    }
    cout << best << endl;
    
    
    cerr << "elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}
