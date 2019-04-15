//
//  main.cpp
//  practice
//
//  Created by Mahmud on 04/30/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MAX = 1005;

int x = 2000000;

long long s = 0, best = x;

long long get(int a, int b) {
    return 1LL * a * (a + 1) / 2 * b * (b + 1) / 2;
}
void update(long long &area, long long &best, int a, int b) {
    long long f = get(a, b);
    if (abs(f - x) < best) {
        best = abs(f - x);
        area = a * b;
    }
}

int main() {
    
    int ptr = x;
    for (int i = 1; i <= x; i ++) {
        while (get(i, ptr) > x) ptr --;
        update(s, best, i, ptr);
        update(s, best, i, ptr + 1);
    }
    cout << s << endl;
    
    return 0;
}
