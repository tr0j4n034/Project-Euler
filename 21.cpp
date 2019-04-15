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

const int MAX = 10001;

int d[MAX << 2];

int main() {
    for (int i = 1; i < MAX; i ++) {
        for (int j = i + i; j < MAX; j += i) d[j] += i;
    }
    int sum = 0;
    for (int i = 1; i < MAX; i ++) {
        if (d[d[i]] == i && i != d[i]) sum += i;
    }
    cout << sum << endl;
    
    return 0;
}
