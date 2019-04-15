//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/14/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 10001;

int a[10];

int main() {
    for (int i = 0; i < 10; i ++) a[i] = i;
    for (int i = 1; i < 1000000; i ++) {
        next_permutation(a, a + 10);
    }
    for (int i = 0; i < 10; i ++) cout << a[i];
    cout << endl;
    
    return 0;
}
