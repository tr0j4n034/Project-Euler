//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/13/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAX = 100000005;

int p[MAX];

int main() {
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        for (int j = i + i; j < MAX; j += i) p[j] = 1;
    }
    
    int a, b, c, l;
    tie(a, b, c, l) = make_tuple(0, 0, 0, -2);
    
    for (int i = -1000; i < 1000; i ++) {
        for (int j = -1000; j < 1001; j ++) {
            for (int n = 0; ; n ++) {
                int v = n * n + i * n + j;
                if (v < 2 || p[v]) {
                    if (n - 1 > l) {
                        l = n - 1;
                        a = i;
                        b = j;
                    }
                    break;
                }
            }
        }
    }
    cout << a * b << endl;
    
    return 0;
}
