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

const int MAX = 10000001;

int d[MAX];

int main() {
    for (int i = 1; i < MAX; i ++) {
        for (int j = i; j < MAX; j += i) d[j] ++;
    }
    int s = 0;
    for (int i = 1; i < MAX - 1; i ++) {
        if (d[i] == d[i + 1]) s ++;
    }
    cout << s << endl;
    
    cout << "elapsed time = " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

