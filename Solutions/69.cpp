//
//  main.cpp
//  practice
//
//  Created by Mahmud on 03/09/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

const int MAX = 1000001;

int phi[MAX], lp[MAX];
pair<int, int> best;

int main() {
    for (int i = 2; i < MAX; i ++) {
        if (lp[i]) continue;
        for (int j = i; j < MAX; j += i) lp[j] = i;
    }
    phi[1] = 1;
    for (int i = 2; i < MAX; i ++) {
        int j = i;
        while (j % lp[i] == 0) j /= lp[i];
        phi[i] = phi[j] * (i / j / lp[i]) * (lp[i] - 1);
    }
    pair<int, int> best = make_pair(1, 1);
    for (int i = 1; i < MAX; i ++) {
        if (1LL * phi[i] * best.second < 1LL * i * best.first) {
            best = make_pair(phi[i], i);
        }
    }
    cout << best.second << endl;
    
    return 0;
}
