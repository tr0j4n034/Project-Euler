//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/14/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 100000001;

int d[MAX];

int main() {
    for (int i = 1; i < MAX; i ++) {
        for (int j = i; j < MAX; j += i) d[j] ++;
    }
    for (int i = 1; ; i ++) {
        int p = i * (i + 1) / 2;
        if (p >= MAX) break;
        if (d[p] >= 500) {
            cout << p << endl;
            return 0;
        }
    }
    
    return 0;
}
