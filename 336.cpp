//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/21/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 11;
const int M = 2011;

int a[N], b[N];

int longest = 0;
vector<string> best;

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 0; i < N; i ++) {
        a[i] = i;
    }
    do {
        for (int i = 0; i < N; i ++) {
            b[i] = a[i];
        }
        int steps = 0;
        for (int i = 0; i < N; i ++) {
            if (b[i] == i) {
                continue;
            }
            int position = -1;
            for (int j = i; j < N; j ++) {
                if (b[j] == i) {
                    position = j;
                    break;
                }
            }
            if (position != N - 1) {
                reverse(b + position, b + N);
                steps ++;
            }
            if (b[i] != i) {
                reverse(b + i, b + N);
                steps ++;
            }
        }
        //        for (int i = 0; i < N; i ++) {
        //            cout << (char)('A' + a[i]);
        //        }
        //        cout << " --> " << steps << endl;
        if (steps > longest) {
            longest = steps;
            best.clear();
            string current = "";
            for (int i = 0; i < N; i ++) {
                current += (char)('A' + a[i]);
            }
            best.push_back(current);
        } else if (steps == longest) {
            string current = "";
            for (int i = 0; i < N; i ++) {
                current += (char)('A' + a[i]);
            }
            best.push_back(current);
        }
    } while (next_permutation(a, a + N));
    
    cout << best[M - 1] << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

