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

const int MAX = 50;

long long f[MAX][MAX];

int main() {
    for (int i = 0; i < MAX; i ++) {
        for (int j = 0; j <= i; j ++) {
            if (i == 0 || j == 0) f[i][j] = 1;
            else f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
        }
    }
    cout << f[40][20] << endl;
    
    return 0;
}
