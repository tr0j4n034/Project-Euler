//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/13/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 101;

int grid[MAX][MAX];

int main() {
    int N = 20, result = 0;
    
    for (int i = 1; i <= 20; i ++) {
        for (int j = 1; j <= 20; j ++) cin >> grid[i][j];
        cout << "line i = " << i << endl;
    }
    for (int i = 1; i + 3 <= 20; i ++) {
        for (int j = 1; j + 3 <= 20; j ++) {
            for (int dx = -1; dx <= 1; dx ++) {
                for (int dy = -1; dy <= 1; dy ++) {
                    if (dx * dx + dy * dy > 0) {
                        result = max(result, grid[i][j] * grid[i + dx][j + dy] * grid[i + 2 * dx][j + 2 * dy] * grid[i + 3 * dx][j + 3 * dy]);
                    }
                }
            }
        }
    }
    cout << result << endl;
    
    return 0;
}
