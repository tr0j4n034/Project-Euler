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

const int MAX = 1000000;

int main() {
    int d = 0, l = 0;
    for (int i = 1; i < MAX; i ++) {
        long long j = i;
        int s = 0;
        while (j > 1) {
            if (j & 1) j = 3 * j + 1;
            else j = j >> 1;
            s ++;
        }
        if (s > l) {
            l = s;
            d = i;
        }
    }
    cout << d << endl;
    
    return 0;
}
