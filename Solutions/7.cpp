//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/13/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAX = 10000005;

int p[MAX];

int main() {
    int N = 10001;
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        N --;
        if (N == 0) {
            cout << i << endl;
            return 0;
        }
        for (int j = i; j < MAX; j += i) p[j] = 1;
    }
    
    
    return 0;
}
