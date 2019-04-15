//
//  main.cpp
//  practice
//
//  Created by Mahmud on 03/20/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <set>
#include <utility>

using namespace std;

const int MAX = 100000000;

int f[MAX], p[MAX];

int main()
{
    for (int i = 1; i < MAX; i ++) {
        for (int j = i; j < MAX; j += i) {
            f[j] ++;
            if (i != 1 && !p[j]) p[j] = i;
        }
    }
    int result = 0;
    for (int i = 2; i < MAX; i ++) {
        if (f[i] == 3 && 1LL * p[i] * p[i] == i) result ++;
        else if (f[i] == 4 && 1LL * p[i] * p[i] != i / p[i]) result ++;
    }
    cout << result << endl;

    return 0;
}
