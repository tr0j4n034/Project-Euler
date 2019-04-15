//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/14/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int d(int n) {
    int s = 0;
    while (n > 0) {
        s ++;
        n /= 10;
    }
    return s;
}
int good(int a, int b, int c) {
    int cnt[10] = {0};
    while (a > 0) {
        cnt[a % 10] ++;
        a /= 10;
    }
    while(b > 0) {
        cnt[b % 10] ++;
        b /= 10;
    }
    while (c > 0) {
        cnt[c % 10] ++;
        c /= 10;
    }
    for (int i = 1; i < 10; i ++) {
        if (cnt[i] != 1) return 0;
    }
    return 1;
}

int main() {
    set<int> s;
    for (int i = 1; i < 2000; i ++) {
        for (int j = i; ; j ++) {
            int k = i * j;
            int dc = d(i) + d(j) + d(k);
            if (dc > 9) break;
            if (dc != 9) continue;
            if (good(i, j, k)) s.insert(k);
        }
    }
    long long sum = 0;
    for (auto i : s) sum += i;
    cout << sum << endl;
    
    return 0;
}
