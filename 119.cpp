//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/4/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#pragma GCC optimize("-0g")

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <ctime>

using namespace std;

const int MAX = 105;

/// oeisable: http://oeis.org/search?q=8+9+81+512+2401+4913+5832+17576+19683&language=english&go=Search

int sum(int N) {
    int s = 0;
    while (N > 0) {
        s += N % 10;
        N /= 10;
    }
    return s;
}
int good(int N) {
    int s = sum(N);
    if (s == 1) return 0;
    while (N % s == 0) N /= s;
    
    if (N == 1) return 1;
    else return 0;
}

int main() {
    cerr << "elapsed: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i < 100000; i ++) {
        if (good(i)) cout << i << endl;
    }
    
    return 0;
}

