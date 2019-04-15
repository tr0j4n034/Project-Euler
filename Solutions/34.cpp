//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/14/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;


int f[10];

int main() {
    f[0] = 1;
    for (int i = 1; i < 10; i ++) f[i] = f[i - 1] * i;
    
    int sum = 0;
    for (int i = 1; i < 10000000; i ++) {
        int j = i, s = 0;
        while (j > 0) {
            s += f[j % 10];
            j /= 10;
        }
        if (s == i) {
            cout << i << endl;
            sum += i;
        }
    }
    cout << sum << endl;
    
    return 0;
}
