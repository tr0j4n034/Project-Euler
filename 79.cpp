//
//  main.cpp
//  practice
//
//  Created by Mahmud on 04/30/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

const int MAX = 100;

int N;
int a[MAX], pos[MAX];

int main() {
    int N = 50;
    for (int i = 1; i <= N; i ++) cin >> a[i];
    
    int p[8] = {0, 1, 2, 3, 6, 7, 8, 9};
    
    do {
        for (int i = 0; i < 8; i ++) {
            pos[p[i]] = i;
        }
        int good = 1;
        for (int i = 1; i <= N; i ++) {
            int x = a[i] / 100;
            int y = a[i] / 10 % 10;
            int z = a[i] % 10;
            if (pos[x] > pos[y]) good = 0;
            if (pos[x] > pos[z]) good = 0;
            if (pos[y] > pos[z]) good = 0;
        }
        if (good) {
            for (int i = 0; i < 8; i ++) cout << p[i];
            cout << endl;
        }
    } while (next_permutation(p, p + 8));
    
    return 0;
}
