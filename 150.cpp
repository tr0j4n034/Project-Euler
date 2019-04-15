//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/05/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 1005;

int a[MAX][MAX];
long long prefix[MAX][MAX];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    int v = 0;
    for (int k = 1, row = 1, column = 1; k <= 500500; k ++) {
        v = (615949LL * v + 797807LL + (1LL << 50)) % (1 << 20);
        a[row][column] = v - (1 << 19);
        if (row == column) {
            row ++;
            column = 1;
        }
        else {
            column ++;
        }
        
    }
    int rows = 1000;
    for (int i = 1; i <= rows; i ++) {
        for (int j = 1; j <= i; j ++) {
            prefix[i][j] = prefix[i][j - 1] + a[i][j];
        }
    }
    long long result = (1LL << 60);
    for (int i = 1; i <= rows; i ++) {
        for (int j = 1; j <= i; j ++) {
            long long sum = 0;
            for (int k = i, q = j; k <= rows; k ++, q ++) {
                sum += prefix[k][q] - prefix[k][j - 1];
                result = min(result, sum);
            }
        }
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

