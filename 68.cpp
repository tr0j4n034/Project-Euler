//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/03/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

const int MAX = 1000000;

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    int a[10];
    for (int i = 0; i < 10; i ++) a[i] = i + 1;
    string best = "";
    do {
        int s1 = a[0] + a[5] + a[6];
        int s2 = a[1] + a[6] + a[7];
        int s3 = a[2] + a[7] + a[8];
        int s4 = a[3] + a[8] + a[9];
        int s5 = a[4] + a[9] + a[5];
        set<int> s = set<int> {s1, s2, s3, s4, s5};
        if ((int)s.size() > 1) continue;
        int id = 0;
        for (int i = 0; i < 5; i ++) {
            if (a[i] < a[id]) {
                id = i;
            }
        }
        string now = "";
        for (int i = 0; i < 5; i ++) {
            if (id == 0) {
                now += to_string(a[0]) + to_string(a[5]) + to_string(a[6]);
            }
            else if (id == 1) {
                now += to_string(a[1]) + to_string(a[6]) + to_string(a[7]);
            }
            else if (id == 2) {
                now += to_string(a[2]) + to_string(a[7]) + to_string(a[8]);
            }
            else if (id == 3) {
                now += to_string(a[3]) + to_string(a[8]) + to_string(a[9]);
            }
            else {
                now += to_string(a[4]) + to_string(a[9]) + to_string(a[5]);
            }
            id = (id + 1) % 5;
        }
        if ((int)now.size() == 16 && now > best) {
            best = now;
        }
    } while (next_permutation(a, a + 10));
    
    cout << best << endl;
    
    return 0;
}
