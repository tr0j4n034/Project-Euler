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

using namespace std;

const int MAX = 700000005;

int cnt = 0;

int get(int N) {
    int r = 0;
    while (N > 0) {
        r = 10 * r + N % 10;
        N /= 10;
    }
    return r;
}
int check(int N) {
    while (N > 0) {
        if ((N % 10) % 2 == 0) return 0;
        N /= 10;
    }
    return 1;
}

int main() {
    cerr << "elapsed time = " << 1. * clock() / CLOCKS_PER_SEC << endl;
    for (int i = 1; i < 1000000000; i ++) {
        if (i % 10 == 0) continue;
        int now = i + get(i);
        if (check(now)) cnt ++;
    }
    cout << cnt << endl;
    cerr << "elapsed time = " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    
    return 0;
}
