//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/20/18.
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

const int MAX = 105;

const int N = 4;

int a[N];
set<double> can[1 << N];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    int best = 0, s = 0;
    
    for (int d1 = 0; d1 < 10; d1 ++) {
        for (int d2 = d1 + 1; d2 < 10; d2 ++) {
            for (int d3 = d2 + 1; d3 < 10; d3 ++) {
                for (int d4 = d3 + 1; d4 < 10; d4 ++) {
                    a[0] = d1;
                    a[1] = d2;
                    a[2] = d3;
                    a[3] = d4;
                    for (int i = 0; i < (1 << N); i ++) can[i].clear();
                    for (int i = 0; i < N; i ++) {
                        can[1 << i].insert(a[i]);
                    }
                    for (int i = 1; i < (1 << N); i ++) {
                        for (int j = 1; j < i; j ++) {
                            if ((i & j) == j) {
                                int other = (i ^ j);
                                for (auto k : can[j]) {
                                    for (auto q : can[other]) {
                                        can[i].insert(k + q);
                                        can[i].insert(k - q);
                                        can[i].insert(q - k);
                                        can[i].insert(k * q);
                                        if (q != 0) can[i].insert(k / q);
                                        if (k != 0) can[i].insert(q / k);
                                    }
                                }
                            }
                        }
                    }
                    int now = 0;
                    set<int> active;
                    for (auto i : can[(1 << N) - 1]) {
                        double up = ceil(i);
                        if (fabs(i - up) < 1.e-9) {
                            active.insert((int)up);
                        }
                    }
                    for (int i = 1; ; i ++) {
                        if (!active.count(i)) {
                            now = i;
                            break;
                        }
                    }
                    if (now > best) {
                        best = now;
                        s = 1000 * a[0] + 100 * a[1] + 10 * a[2] + a[3];
                    }
                }
            }
        }
    }
    cout << s << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

