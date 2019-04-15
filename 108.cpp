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

const int MAX = 555555;

int p[MAX], lp[MAX];

int get(int N) {
    int s = 1;
    while (N > 1) {
        int d = lp[N], cnt = 0;
        while (N % d == 0) {
            cnt ++;
            N /= d;
        }
        s *= 2 * cnt + 1;
    }
    return (s + 1) / 2;
}

int main() {
    lp[1] = 1;
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        for (int j = i; j < MAX; j += i) {
            p[j] = 1;
            lp[j] = i;
        }
    }
    for (int i = 1; i < MAX; i ++) {
        if (get(i) > 1000) {
            cout << i << endl;
            break;
        }
    }
    
    
    return 0;
}
