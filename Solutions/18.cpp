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

const int MAX = 101;

int grid[MAX][MAX];

int main() {
    int N = 15;
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= i; j ++) cin >> grid[i][j];
    }
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= i; j ++) {
            grid[i][j] += max(grid[i - 1][j - 1], grid[i - 1][j]);
        }
    }
    int result = 0;
    for (int i = 1; i <= N; i ++) result = max(result, grid[N][i]);
    cout << result << endl;
    
    return 0;
}
