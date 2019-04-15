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

const int MAX = 1000000;

int p[MAX];

int main() {
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        for (int j = i; j < MAX; j += i) p[j] ++;
    }
    for (int i = 1; i < MAX; i ++) {
        if (p[i] == 4 && p[i + 1] == 4 && p[i + 2] == 4 && p[i + 3] == 4) {
            cout << i << endl;
            return 0;
        }
    }
    
    return 0;
}
