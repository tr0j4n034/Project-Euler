//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/15/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

const int MAX = 100000;

int p[MAX];

int main() {
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        for (int j = i + i; j < MAX; j += i) p[j] = 1;
    }
    for (int i = 3; i < MAX; i += 2) {
        if (!p[i]) continue;
        int good = 1;
        for (int j = 1; 2 * j * j < i; j ++) {
            if (!p[i - 2 * j * j]) {
                good = 0;
                break;
            }
        }
        if (good) {
            cout << i << endl;
            return 0;
        }
    }
    
    return 0;
}
