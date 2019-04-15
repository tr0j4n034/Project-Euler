//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/19/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAX = 2305;

int data[MAX][MAX];

int main() {
    int N = 1001;
    int steps = 2, current = 0;
    int sx = (N + 3) >> 1, sy = sx - 1;
    
    while (current < N * N) {
        for (int i = 0; i < steps && current < N * N; i ++) {
            data[sx][sy ++] = ++current;
        }
        if (current >= N * N) break;
        sy --;
        -- current;
        for (int i = 0; i < steps && current < N * N; i ++) {
            data[sx --][sy] = ++current;
        }
        if (current >= N * N) break;
        sx ++;
        -- current;
        steps ++;
        for (int i = 0; i < steps && current < N * N; i ++) {
            data[sx][sy --] = ++current;
        }
        if (current >= N * N) break;
        sy ++;
        -- current;
        for (int i = 0; i < steps && current < N * N; i ++) {
            data[sx ++][sy] = ++current;
        }
        if (current >= N * N) break;
        sx --;
        -- current;
        steps ++;
    }
//    for (int i = 1; i < MAX; i ++) {
//        int printed = 0;
//        for (int j = 1; j < MAX; j ++) {
//            if (data[i][j] != 0) {
//                cout << data[i][j] << " ";
//                printed = 1;
//            }
//        }
//        if (printed) cout << endl;
//    }
    
    int sum = 0, x = -1, y = 0;
    for (int i = 1; i < MAX && x == -1; i ++) {
        for (int j = 1; j < MAX && x == -1; j ++) {
            if (data[i][j] != 0) {
                x = i;
                y = j;
            }
        }
    }
    for (int i = 1; i <= N; i ++) {
        sum += data[x + i - 1][y + i - 1];
    }
    for (int i = 1; i <= N; i ++) {
        sum += data[x + i - 1][y + N - i];
    }
    if (N & 1) sum -= data[x + (N >> 1)][y + (N >> 1)];
    
    cout << sum << endl;
    
    return 0;
}
